#include "demo_cpr_window.h"
#include <imgui.h>
#include <cpr/cpr.h>
#include <string>

void ShowDemoCprWindow() {
    static char url[256] = "https://api.github.com";
    static char response_text[4096] = "";
    static bool loading = false;
    static int status_code = 0;

    ImGui::Begin("DemoCprWindow");
    ImGui::InputText("URL", url, sizeof(url));
    if (ImGui::Button("Send GET Request") && !loading) {
        loading = true;
        auto response = cpr::Get(cpr::Url{std::string(url)});
        status_code = response.status_code;
        strncpy(response_text, response.text.c_str(), sizeof(response_text) - 1);
        response_text[sizeof(response_text) - 1] = '\0';
        loading = false;
    }
    if (loading) {
        ImGui::Text("Loading...");
    } else {
        ImGui::Text("Status: %d", status_code);
        ImGui::InputTextMultiline("Response", response_text, sizeof(response_text), ImVec2(400, 200));
    }
    ImGui::End();
}
