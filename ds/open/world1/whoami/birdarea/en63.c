#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit __DIR__"muder.c";
void create()
{
 set("short",HIW"�F�_"NOR"�A�L"NOR"��"YEL"�d�h��"NOR);
 set("long",@LONG 
����d�h�Ϫ����[�p��, ���M�|�P���۩_�Ǫ��Ӫ�, ���w�g
�O�L���, �]�u�n�w���Y�֩��e��. �i�O�A�Pı���Ǫ����n
���C�C�i�}�����ᦷ, �H�ɤ@�f��A�Y��!
LONG);
 set("exits",(["southwest":__DIR__"en67",
               "southeast":__DIR__"en69",
               ]));
 set("objects",([__DIR__"npc/flower" : 4+random(4),
               ]));
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        

