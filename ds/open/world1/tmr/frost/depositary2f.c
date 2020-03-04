// Room: /open/world1/tmr/frost/depositary2f.c

inherit ROOM;

void create()
{
	set("short", "�øg�դG��");
	set("long", @LONG
�h�ƹD�Юc�[���ؿv���ǲΪ��쵲�c�ؿv�A�Y�H��[�����F�A�����
�j��A�Υ˻\�γ��A������j���ȧ@�����~���j���ΡA���t�γ����q�C��
�øg�իh�O�ݩ�o���ؿv�A�Ӱ��C�h�A�îѸU���A���[�����D�n�ؿv���@
�A���`�O����~�H���N�i�X�C�ӳo��O�øg�ժ��G�ӡC
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dragon-tiger" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"depositary3f",
  "down" : __DIR__"depositary",
]));
	set("no_clean_up", 0);
	set("current_light", 4);

	setup();
}
int valid_leave(object me, string dir)
{
        ::valid_leave();
   
   if( dir == "up"
                && objectp( present("dragon tiger", this_object()) ) ) {
                        message_vision( "�s����$N�q�s�@�n�A����$N�W�ӡC\n", me);
                        return 0;
        }
        return ::valid_leave(me,dir);
}


