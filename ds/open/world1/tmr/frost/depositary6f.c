// Room: /open/world1/tmr/frost/depositary3f.c

inherit ROOM;

void create()
{
        set("short", "�øg�դ���");
        set("long", @LONG
�h�ƹD�Юc�[���ؿv���ǲΪ��쵲�c�ؿv�A�Y�H��[�����F�A�����
�j��A�Υ˻\�γ��A������j���ȧ@�����~���j���ΡA���t�γ����q�C��
�øg�իh�O�ݩ�o���ؿv�A�Ӱ��C�h�A�îѸU���A���[�����D�n�ؿv���@
�A���`�O����~�H���N�i�X�C�ӳo��O�øg�ժ����ӡC
LONG
        );
        set("current_light", 3);
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
//  __DIR__"npc/dragon-tiger" : 1,
]));
        set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"depositary5f",
  "up" : __DIR__"depositary7f",
]));

        setup();
        replace_program(ROOM);
}


