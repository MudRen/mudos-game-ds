#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�y����"NOR"��"HIC"�^���v"NOR);
 set("long",@LONG
�o�̴N�O�y�����^������ҤF�E�A�r�M�@�ݡA���e�~�M����
��W�l�@�˰��j�������A�ݨӳo�N�O�E���������F�A�o�ӭ^����
�Ӥ]�O���⤣�Z�E
LONG);
 set("item_desc",([
        "����":"�o���������ӴN�O�E���������A�W���������o�X����E\n",     ]));
 set("objects",([__DIR__"npc/hero" : 1,
               ]));
 set("exits",([
               "east":__DIR__"village13", 
               ]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
}

