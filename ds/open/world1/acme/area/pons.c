inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
�A���B�b�@�y������W�A������O�ΤW�n������سy�Ӧ��A�q�����
�U��h�A�O�@�����Ƽe���p�ˬy�A�Y�����^�������|���ͩR�M�I�C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"wewd1",
  "northwest" : __DIR__"wewd",
]));
  set("item_desc", ([ /* sizeof() == 1 */
   "�p��" : "�o�p�ˤ��O�ܲ`�A�γ\\�੹�U��(jump down)�C\n",
  ]));
        set("no_clean_up", 0);
     set("outdoors","land");

        setup();
}
void init()
{ 
         add_action("do_jump","jump");
}
int do_jump(string arg)
{
          object me;
          me=this_player();
          if(arg != "down")
            return 0;
          else {
            message_vision("$N���p�˸̸��F�U�h�C\n",me);
            me->move(__DIR__"l4");
            return 1;
          }
}
