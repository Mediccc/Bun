#include "navigation.h"
#include <windows.h>

/* helper function to handle our UI's pages */
void HandlePages() {
    if (Bun::selectedPage == 0) {
        ImGui::SetCursorPos(ImVec2(170, 34)); /* set the cursor pos for the page background */
        Bun::NavigationPage("HomePage", pageSize, []() { /* create the first/home page */
            ImGui::Text("Hello! This is the home page.");
            ImGui::Spacing();
            if (Bun::Button("Click Me!")) { /* custom Bun button with hover effects/animations */
                MessageBoxA(NULL, "You clicked me!", "Wow!", MB_OK);
            }
        });
    }
    else if (Bun::selectedPage == 1) {
        ImGui::SetCursorPos(ImVec2(170, 34));
        Bun::NavigationPage("SecondPage", pageSize, []() { /* create the second page */
            ImGui::BunCheckbox("Checkbox 1", &test); /* custom Bun checkbox with hover effects/animations */
            ImGui::Spacing();
            ImGui::BunCheckbox("Checkbox 2", &test2);
            ImGui::Spacing();
            ImGui::BunCheckbox("Checkbox 3", &test3);
        });
    }
    else if (Bun::selectedPage == 2) {
        ImGui::SetCursorPos(ImVec2(170, 34));
        Bun::NavigationPage("ThirdPage", pageSize, []() {
        });
    }
}

void NavigationExample() {
    /* set up the navigation bar and buttons */;
    Bun::NavigationBar("NavBar", ImVec2(150, 360));

    ImGui::Spacing();
    if (Bun::NavigationButton("Page 1", ImVec2(130, 35))) {
        Bun::selectedPage = 0;
    }

    ImGui::Spacing();

    if (Bun::NavigationButton("Page 2", ImVec2(130, 35))) {
        Bun::selectedPage = 1;
    }

    ImGui::Spacing();

    if (Bun::NavigationButton("Page 3", ImVec2(130, 35))) {
        Bun::selectedPage = 2;
    }


    HandlePages();
}