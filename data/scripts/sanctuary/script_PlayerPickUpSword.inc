@ Player at Sanctuary pick up sword
SCRIPT_START script_PlayerPickUpSword
	PlaySound SFX_1D3
	CallWithArg SetPlayerAnimation2, 0x000008bf
	Call sub_08096028
	Wait 0x003c
	SetSyncFlag 0x00020000
	Call WaitForPlayerFrameHiBit
	Wait 0x0078
	WaitForSyncFlagAndClear 0x00040000
	Call sub_080791BC
SCRIPT_END
	.2byte 0x0000