// Room: /d/xiangyang/guofugate.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "�����j��");
	set("long", 
"�@�y�ؿv�j�몺�j�v�|�X�{�b�A�����e�C�u�����Ӱ��D�A
�W�Ѩ�Ӥj�r"HIY"
                     ��   ��
"NOR"
    ���u�вĤG�N�̤l�C�߻��M�X�Ӯa�B���b���e���ݫe�ӫO
���������U��q�h�C\n"
 );
        set("outdoors", "xiangyang");
	set("exits", ([
		"south" : __DIR__"westjie1",
		"north" : __DIR__"guofuyuan",
	]));
	set("objects", ([
//          __DIR__"npc/yelvqi" : 1,
          __DIR__"npc/jiading" : 2,

	]));
	set("coor/x", -520);
	set("coor/y", -490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
