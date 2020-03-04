// Room: /u/a/alickyuen/area/zoo19.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST�CStation�ICyberZoo"NOR);
	set("long", @LONG
�o�جO�ʪ��骺�|���B�A�S������S�O�A�A�u�O�ݨ�@�i��l�A�Y�A
�o�{������_�ǨƱ��Φ��@�ǰʪ��X�����ܳ��i�H�ӳo�̳q���o�̪��޲z
���C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"zoo6",
]));
        set("item_desc", ([ /* sizeof() == 1 */
  "��l" : "�@�i�ΦB������l�A�O�ΤF���Ӫ��̷s����ިӰ����A�ҥH���ǦB���|��\n"
"�ơC�o�i��l������z�A�A�ϩ��ݨ�����b�{�ۡC\n",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);
	setup();
}
void init()
{
add_action("do_search","search");
}
int do_search(string arg)
{
        object me, obj;
        me=this_player();
        if (arg != "��l" || me->query_temp("quest/animal") ) 
                   return 0;
        else {
                   message_vision("$N�V�V½½�A�o�{�ੳ���@�Ӭ��⪺��C\n\n" ,me);
me->set_temp("quest/animal",1);
obj=new(__DIR__"npc/controller2");
obj->move(__DIR__"zoo19");
           return 1;
                 }
}
