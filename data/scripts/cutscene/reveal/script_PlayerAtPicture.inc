@ Player in Sanctuary at picture
SCRIPT_START script_PlayerAtPicture
	BeginBlock
	SetEntitySpeed 0x0080
	EndBlock
	DoPostScriptAction 0x0001
	_0807EDD4 0x0098, 0x0058
	SetAnimationState 0x0000
	DoPostScriptAction 0x0000
	SetSyncFlag 0x00000002
	Call sub_080791BC
SCRIPT_END