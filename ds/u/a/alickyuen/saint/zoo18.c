// Room: /u/a/alickyuen/area/zoo18.c
//updated by 26/12
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", HIC"ST�CSecret�ICyberZoo"NOR);
        set("long", @LONG
�o�O�p�Τ����@���ũж��A�o�̫D�`²���A�u���@�Ӧ��d�C���A�ݨ�
�F�@�ӤH�����b�ж����������A�L���������������L�b������D�N�C�P��
�A�A�]�ݨ�o�̦��@�ӤG�Ӫ�Ţ�l��b�a�W�A�ӧA�ݨ�Ţ�l�̳��M���D�D
�D�D�D�D
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"zoo17",
]));
create_door("out","�j�K��","enter",DOOR_CLOSED);
set("objects", ([
__DIR__"npc/seller2.c" :1,
]));
        set("light",1);
        set("world", "future");
        set("no_clean_up", 0);
        set("item_desc",(["���d":"�@�Ӵ��q�����d,�̭���ۤ@�Ǧ�A�C\n",])); 
        setup();
}

void init()
{
        add_action("do_search","search");
}

int do_search(string arg)
{
object ring;
        object me;
        me=this_player();
        if (!arg || arg != "��A") 
                   return 0;
        if(query_temp("getring")) 
                return notify_fail("��F�S��A�רs�@�L����...\n");
        message_vision("$N�b��A�̧�F��A�ש󵹧A���F�@����⪺�٫��C\n\n" ,me);
        ring=new(__DIR__"obj/ring");
        ring->move(me);
        set_temp("getring",1);      
        return 1;  
}

void reset()
{
        if(query_temp("getring") )
                delete_temp("getring");
}

