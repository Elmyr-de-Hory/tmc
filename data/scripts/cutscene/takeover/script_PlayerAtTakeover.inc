@ Player at Western Wood Cutscene
SCRIPT_START script_PlayerAtTakeover
	BeginBlock
	SetEntitySpeed 0x0080
	EndBlock
	DoPostScriptAction 0x0001
	_0807EDD4 0x0168, 0x0058
	SetAnimationState 0x0004
	DoPostScriptAction 0x0000
	CallWithArg SetPlayerAnimation2, 0x000003c5
	Call WaitForPlayerFrameHiBit
	MessageFromTargetPos 0x1318, 0x000c
	WaitUntilTextboxCloses
	CallWithArg SetPlayerAnimation2, 0x000003c9
	Call WaitForPlayerFrameHiBit
	SetAnimationState 0x0004
	DoPostScriptAction 0x0000
	SetSyncFlag 0x00000100
	Call sub_080791BC
SCRIPT_END