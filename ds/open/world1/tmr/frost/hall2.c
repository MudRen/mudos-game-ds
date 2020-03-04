// Room: /open/world1/tmr/frost/hall2.c

inherit ROOM;

void create()
{
	set("short", "�j���ȷ�");
	set("long", @LONG
�j���ȷ��y�_�V�n�A�e����ΡA���e�즳�X���A���e����O�A�ⰼ�t��
�U�����C��������O���來�����E�������p�¡C�j���ȷ����H�x�Ѷ�a�誺
��h�ӻաA�W�h���@�Ϋγ��A�H�x�ѡA�갮���}�F�U�h����ΡA�H�x�a�A��
�[�s�t�C��ӫؿv�G���Y�ԡA��ն����A�륩�ӽo�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"court3",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
        set("objects", ([
                 __DIR__"npc/yun-zhong-zi":1,
        ]) );



	setup();
	replace_program(ROOM);
}
