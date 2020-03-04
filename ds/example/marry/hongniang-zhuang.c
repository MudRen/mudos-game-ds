//Room: /d/ruzhou/hongniang-zhaung.c
// by llm 99/06/12

#include <ansi.h>

inherit ROOM;

string look_sign(object me);

void create()
{
	set("short", "���Q��");
   set("long", @LONG
�o���N�O�ѤU�Ұ��w�����t�����Q��A�u���b�o���l���B���άO�Ѱ�
�B���~��o��@�H���ӻ{�C�o���O�@�Ӥ��j�����U�A���O�g�L�@�f�׾㤧
�Z�A��o�Q���a�𬣡C�U�󥿤��E�ۤ@���J�ۦr���Q��еP(sign)�C
LONG
        );
	set("exits", ([
		"west" : __DIR__"hong-zoulang",
		"east" : __DIR__"yinyuan-tang",
   ]) );

   set("item_desc", ([
   	"sign": (: look_sign :),
   ]) );

   set("objects", ([
   	__DIR__"npc/meipo" : 1,
      ]) );
   setup();
}

string look_sign(object me)
{
	return HIM"�U�M���U��\n"
   "�D�t��D��\n"
   "���u�e�ͨt\n"
   "�õ��@�@�H\n"NOR;
}

int valid_leave(object me, string dir)
{
 	if (dir=="west"&& me->query_temp("pending/pro") )
      me->delete_temp("pending/pro");
      return ::valid_leave(me, dir);
}