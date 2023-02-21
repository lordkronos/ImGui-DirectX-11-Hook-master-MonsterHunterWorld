#include "includes.h"
#include "memory.h"
#include "options.h"
#include "GameBase.h"

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;

void InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

bool init = false;

bool ShowMenu = true;
bool PlayerGodMode = false;
bool unlgoldbool = false;
bool SkyColorEnabled = false;
bool bStamina = false;
bool bCriticalDamage = false;
bool bspeed = false;

static int tab = 0;

BaseAddies::Module Mod;





void MenuCreateStyle()
{
	ImGui::StyleColorsLight();

	ImGuiStyle _style;
	ImGuiStyle* style = &ImGui::GetStyle();
	_style.WindowPadding = ImVec2(15, 15);
	_style.WindowRounding = 1.0f;
	_style.FramePadding = ImVec2(5, 5);
	_style.FrameRounding = 1.0f;
	_style.ItemSpacing = ImVec2(12, 8);
	_style.ItemInnerSpacing = ImVec2(8, 6);
	_style.IndentSpacing = 25.0f;
	_style.ScrollbarSize = 15.0f;
	_style.ScrollbarRounding = 1.0f;
	_style.GrabMinSize = 5.0f;
	_style.GrabRounding = 1.0f;

	_style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	_style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	//_style.Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	_style.Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	_style.Colors[ImGuiCol_Border] = ImVec4(0.80f, 0.80f, 0.83f, 0.88f);
	_style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
	//_style.Colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	//_style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	//_style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	_style.Colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	_style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 0.98f, 0.95f, 0.75f);
	_style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	_style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	_style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	_style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	_style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	_style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	_style.Colors[ImGuiCol_CheckMark] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	_style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	_style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	_style.Colors[ImGuiCol_Button] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	_style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	_style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	_style.Colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	_style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	_style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	_style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	_style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	_style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	_style.Colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	_style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
	_style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	_style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
	_style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
	_style.Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(1.00f, 0.98f, 0.95f, 0.73f);
	ImGui::GetStyle() = _style;
}


HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (!init)
	{
		InitPattern();

		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)& pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)& pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			InitImGui();
			init = true;
		}

		else
			return oPresent(pSwapChain, SyncInterval, Flags);
	}

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	if (GetAsyncKeyState(VK_INSERT) & 1)
	{
		ShowMenu = !ShowMenu;
	}


	if (ShowMenu)
	{


		ImGui::SetNextWindowSize(ImVec2{ 325, 275 });
		ImGui::Begin("Karss _TitanQ v1.0", &ShowMenu, ImGuiWindowFlags_NoResize);
		if (ImGui::Button("Hacks", ImVec2(80, 28))) {
			tab = 0;
		}
		ImGui::SameLine(0, 10);
		if (ImGui::Button("Misc", ImVec2(80, 28))) {
			tab = 1;
		}
		ImGui::SameLine(0, 10);
		if (ImGui::Button("Options", ImVec2(80, 28))) {
			tab = 2;
		}

		


		// // // // // // // // // // // Hacks
		if (tab == 0)
		{

			ImGui::Checkbox("Player_GodMode", &PlayerGodMode);
			if (PlayerGodMode)
			{
				Mod.LocalPlayer->HealthInitial = 250;
				Mod.LocalPlayer->HealthMax = 250;
				Mod.LocalPlayer->HpRecoverAmount = 100;
				Mod.LocalPlayer->HpRecoverRatio = 100;

				//Memory::Patch((BYTE*)(GodMode), (BYTE*)"\x90\x90\x90\x90\x90\x90\x90\x90", 8);

			}
			else
			{
				Mod.LocalPlayer->HealthInitial = 100;
				Mod.LocalPlayer->HealthMax = 150;

				//Memory::Patch((BYTE*)(GodMode), (BYTE*)"\xF3\x0F\x11\xB3\x50\x01\x00\x00", 8);
			}

		

			ImGui::Checkbox("Player_UnlStamina", &bStamina);
			if (bStamina)
			{
				Mod.LocalPlayer->StaminaRegenRate = 100;
				
		
			}
			else
			{
				Mod.LocalPlayer->StaminaRegenRate = 25;
				
			}
			
			ImGui::Checkbox("Player_CriticalDamage", &bCriticalDamage);
			if (bCriticalDamage)
			{
				Mod.LocalPlayer->CriticalDamage = 3.5;

			}
			else
			{
				Mod.LocalPlayer->CriticalDamage = 1.25;
			}

			ImGui::Checkbox("Player_Speed", &bspeed);
			if (bspeed)
			{
				Mod.LocalPlayer->WalkMotionSpeed = 2.25;
				Mod.LocalPlayer->RunMotionSpeed = 2.5;
			}
			else
			{
				Mod.LocalPlayer->WalkMotionSpeed = 1.25;
				Mod.LocalPlayer->RunMotionSpeed = 1.25;
			}



		}




		//  // // //  // // /// // // ESP
		if (tab == 1) {

			

		}


		//  // // //  // // /// // // MISC
		if (tab == 2)
		{

			


		}

		ImGui::Separator();
		if (ImGui::Button("Unload"))
		{
			kiero::shutdown();
		}
		
		ImGui::End();
	}

	MenuCreateStyle();

	ImGui::Render();

	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return oPresent(pSwapChain, SyncInterval, Flags);
}

DWORD WINAPI MainThread(LPVOID lpReserved)
{
	bool init_hook = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(8, (void**)& oPresent, hkPresent);
			init_hook = true;
		}
	} while (!init_hook);
	return TRUE;
}

BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hMod);
		CreateThread(nullptr, 0, MainThread, hMod, 0, nullptr);
		break;
	case DLL_PROCESS_DETACH:
		kiero::shutdown();
		break;
	}
	return TRUE;
}

