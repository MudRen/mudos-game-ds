// Room: /open/world1/tmr/frost/depositary3f.c

inherit ROOM;

void create()
{
        set("short", "�øg�դT��");
        set("long", @LONG
�h�ƹD�Юc�[���ؿv���ǲΪ��쵲�c�ؿv�A�Y�H��[�����F�A�����
�j��A�Υ˻\�γ��A������j���ȧ@�����~���j���ΡA���t�γ����q�C��
�øg�իh�O�ݩ�o���ؿv�A�Ӱ��C�h�A�îѸU���A���[�����D�n�ؿv���@
�A���`�O����~�H���N�i�X�C�ӳo��O�øg�ժ��T�ӡC
LONG
        );
        set("current_light", 3);
        set("objects", ([ /* sizeof() == 1 */
                      __DIR__"npc/book1" : 4,
        ]));

        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"depositary2f",
  "up" : __DIR__"depositary4f",
]));

        setup();
}


int valid_leave(object me, string dir)
{
        ::valid_leave();
   
   if( dir == "up"
                && objectp( present("_MORALITY_BOOK_", this_object()) ) ) {
                        message_vision( "�D�w���צb$N���e����$N�W�ӡC\n", me);
                        return 0;
        }
        return ::valid_leave(me,dir);
}

