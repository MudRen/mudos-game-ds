#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit __DIR__"muder.c";
void create()
{
 set("short",HIW"�F�_"NOR"�A�L"NOR"��"YEL"�d�h��"NOR);
 set("long",@LONG
�g�L���~�[�A, �A���G�w�g���ӤF������O, ��O��F�@��
����w������U�𮧵�, ���g�D����^�٬O���A�H�ɫO��ĵ�٤�
. ��M�o�{�Y�W���X�����۩ǲ����e��, ���ѱo�޻L�N�]..
LONG);
 set("exits",(["east":__DIR__"en67",
               "southwest":__DIR__"en70",
               ]));
 set("objects",([__DIR__"npc/bee" : 3+random(3),
               ]));
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        

