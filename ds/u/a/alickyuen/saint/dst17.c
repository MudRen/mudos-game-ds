//updated 27/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"Circle tunnel�ISaint"NOR);
       set("long",@long
�A�����ۤ@���s��saint ���M�q�Ϫ���H�q�D�A���n�����i�q���¥@
�ɱ��q�ϡA���_�����B�N�O�����F�A�ɬO�������H��C�o���q�D�e�B�b�@
��ާΪ����@�������A�����a�j���F�q�Ϥ���©���D���Ů�C
long
);
	set("exits", ([ /* sizeof() == 1 */
  // "south" : __DIR__"pass1.c", ��s�q��
"enter":__DIR__"gate1.c",
]));
   set("outdoors","land");
	setup();
}
