#include "Application.h"
#include "imgui.h"
#include <string>
#include <cmath>

#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"
#include <d3d9.h>


namespace BMICalc
{

    float weight = 0.f;
    float height = 0.f;
    int bmi;
    const char* userInfo = "";

    void RenderUI()
    {
        ImGui::Begin("BMI Calculator", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_MenuBar);
        ImGui::SetWindowSize(ImVec2(720, 500));
        ImGui::SetWindowPos(ImVec2(0, 0));

        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("Menu"))
            {
                if (ImGui::MenuItem("Close", "Alt+F4"))
                {
                    ImGui_ImplDX9_Shutdown();
                    ImGui_ImplWin32_Shutdown();
                    ImGui::DestroyContext();
                }
                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }

        ImGui::Text("                                                                  Welcome to BMI Calculator!");
        ImGui::NewLine();

        ImGui::InputFloat("Enter your weight (kg)", &weight, 1);
        
        ImGui::InputFloat("Enter your height (cm)", &height, 1);

        if (ImGui::Button("Calculate"))
        {
            float heightToMeters = height / 100;
            float readyHeight = heightToMeters * heightToMeters;

            bmi = round(weight / readyHeight);
            

            if (bmi <= 18.4)
            {
                userInfo = "You have Underweight";
            }

            if (bmi >= 18.5 && bmi <= 24.9)
            {
                userInfo = "You have Normal";
            }

            if (bmi >= 25 && bmi <= 39.9)
            {
                userInfo = "You have Overweight";
            }

            if (bmi >= 40)
            {
                userInfo = "You have Obese";
            }
        }

        std::string bmiResultStr = std::to_string(bmi);
        std::string bmiResultOutput = "Your BMI is " + bmiResultStr + " kg/m^2";
        const char* bmiResult = bmiResultOutput.c_str();

        ImGui::Text(bmiResult);
        ImGui::Text(userInfo);


        ImGui::NewLine();
        ImGui::NewLine();

        ImGui::Text("Info: ");
        ImGui::NewLine();

        ImGui::Text("The Body Mass Index (BMI) Calculator can be used to calculate BMI value and corresponding weight");
        ImGui::Text("status while taking age into consideration. Use the 'Metric Units' tab for the International System of");
        ImGui::Text("Units or the 'Other Units' tab to convert units into either US or metric units.Note that the calculator");
        ImGui::Text("also computes the Ponderal Index in addition to BMI, both of which are discussed below in detail.");


        ImGui::End();
    }
}
