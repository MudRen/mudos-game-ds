// Room: /u/a/alickyuen/area/dr9.c

inherit ROOM;

void create()
{
	set("short", "ST�CHospital�ILift");
	set("long", @LONG
�A����ӳo�ءA�u�o�{���F�@�ǫ��s�~�K�S����L�F�F�F�C�o������
�N�O�o����|���ǰe���A����ө���|�U�h�C
�@�@�A�{�b�b��|���G�ӡC
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "���s" : "�A�ݨ����s�W��1�M3��Ө�C",
]));
	set("world", "future");
	set("light", 1);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"dr11",
]));
	set("no_clean_up", 0);

	setup();
}
void init()
{
 add_action("typepush","push");
}
int typepush(string arg)
{
        object me;
        me=this_player();
if(!arg) return notify_fail("�A���F�@�|��A����]�S���o�͹L�D\n");
 if(arg=="1")
 {
         message_vision("��M�@�}�j���A$N�b�o�ж������F�C\n", me);
         me->move(__DIR__"dr8");
         return 1;
 }
 if(arg=="3")
 {
         message_vision("��M�@�}�j���A$N�b�o�ж������F�C\n", me);
         me->move(__DIR__"dr10");
         return 1;
 }
}
