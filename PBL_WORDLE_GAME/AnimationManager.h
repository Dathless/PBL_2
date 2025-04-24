#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Collections::Generic;

namespace PBLWORDLEGAME {
    public ref class BounceAnimation {
    private:
        Control^ ctrl;
        int originalY;
        int direction;
        int bounceRange;
        int currentOffset;
        Timer^ timer;

        static int bounceSpeed = 2;

        void OnTick(Object^ sender, EventArgs^ e) {
            currentOffset += direction * bounceSpeed;

            if (Math::Abs(currentOffset) >= bounceRange)
                direction *= -1;

            Point newLoc = ctrl->Location;
            newLoc.Y = originalY + currentOffset;
            ctrl->Location = newLoc;
        }

    public:
        BounceAnimation(Control^ targetCtrl) {
            ctrl = targetCtrl;
            originalY = ctrl->Location.Y;
            direction = -1;
            bounceRange = 8;
            currentOffset = 0;

            timer = gcnew Timer();
            timer->Interval = 30;
            timer->Tick += gcnew EventHandler(this, &BounceAnimation::OnTick);
            timer->Start();
        }

        void Stop() {
            if (timer != nullptr) timer->Stop();
        }

        ~BounceAnimation() {
            Stop();
        }
    };
    public ref class SideBarManager {
    private:
        Panel^ sidebar;
        Button^ toggleBtn;
        int sideBarW;
        bool isVisible;
        Timer^ sidebarTimer;
    public:
        SideBarManager(Panel^ sidebar, Button^ toggle) {
            this->sidebar = sidebar;
            toggleBtn = toggle;
            sideBarW = sidebar->Width;
            isVisible = true;
            sidebarTimer = gcnew Timer();
            sidebarTimer->Interval = 10;
            sidebarTimer->Tick += gcnew System::EventHandler(this, &SideBarManager::SidebarAnimate);
            toggleBtn->Click += gcnew System::EventHandler(this, &SideBarManager::toggleSidebar);
        }
    private:
        System::Void toggleSidebar(Object^ sender, EventArgs^ e) {
            sidebarTimer->Start();
        }
        System::Void SidebarAnimate(Object^ sender, EventArgs^ e) {
            int step = 10;
            if (isVisible) {
                if (sidebar->Left > -sideBarW) {
                    sidebar->Left -= step;
                    toggleBtn->Left -= step;
                }
                else {
                    sidebarTimer->Stop();
                    isVisible = false;
                    toggleBtn->Text = ">>";
                }
            }
            else {
                if (sidebar->Left < 0) {
                    sidebar->Left += 10;
                    toggleBtn->Left += 10;
                }
                else {
                    sidebarTimer->Stop();
                    isVisible = true;
                    toggleBtn->Text = "<<";
                }
            }
        }
    };
}
