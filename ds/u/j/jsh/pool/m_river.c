inherit ROOM;
void create()
{
        set("short", "�e��p��");
        set("long", @LONG
�A�����b�e��p���A�u�~�i�ݨ줣�֧������ۤ���ۦb�e��l���@��
�窫�A�]�����ֳ��ȥ��b�ɨ��������ֽ�C���e�]�Q�ޥγq����~���A��
������A�C���򤧮ɡA���e�����o���u�餣���A���٤@���C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "northeast" : "/open/world1/tmr/area/vroad3",
]));
set("item_desc", ([
    "�¬}" : "�@�Ӷ¶ª��}�A�ݨӥi�H�i�h(enter)...���L���Z�`��...�n�p�ߡC\n",
]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_enter","enter");
}
int do_enter(string arg)
{
          object me;
          me=this_player();
          if(arg != "�¬}")
            return 0;
          else {
            message_vision("$N���¬}����V��F�L�h�C\n",me);
            me->move("/open/world1/moonhide/pool/room1");
            return 1;
          }
}

