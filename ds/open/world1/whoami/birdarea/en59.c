#include <ansi.h>
#include <room.h> 
inherit ROOM;
inherit __DIR__"muder.c";
void create()
{
 set("short",HIW"�F�_"NOR"�A�L"NOR"��"YEL"�d�h��"NOR);
 set("long",@LONG
�A�@�L�Y������B�è�, �oı�o�̬O�d�h�Ϫ���t. �����B
�N�~���w�R, �Ϧ����H�S���w�ߪ��Pı, ��M�I��@�}�����j�L
, ���A�������֪��D���_�ӤF.
LONG);
 set("exits",(["west":__DIR__"en58",
               "northwest":__DIR__"en54",
               "south":__DIR__"en64",
               ]));
 set("objects",([__DIR__"npc/animal" : 4+random(4),
               ]));
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        

