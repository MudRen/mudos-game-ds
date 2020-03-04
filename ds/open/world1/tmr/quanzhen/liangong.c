// liangong.c �m�\��
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�m�\��");
        set("long", @LONG
�o�̬O���u�Ч̤l�m�\���ж��C�o�y�ж��Ϊ��ƬO�_�S�A�e��
��e�A������ΡA�F��b��A����o�@�T���Ϊ��A��ӳo�O���u��
�W�����m�\�ǡA�e���m�x�A��e�ϫ��A�F���C�A�訤�o��C�ж�
�����ߵ۴X�ӽm�\�Ϊ���H�A�ݵ۴X�ӨF�U(bag)�M�ȥU(paper)�C
LONG );

        set("exits", ([
                "south" : __DIR__"houtang2",
                "north" : __DIR__"chanfang2",
        ]));
        set("item_desc", ([
                "paper" : "�o�O�@��p�p�����֯ȥU�A���K�v�v�b��W�C�n���i�H
�Ψӽm�x�k���A����(da paper)�ոլݡC\n",
                "bag"   : "�o�O�@�Ӥj�F�U�A�ݰ_�ӫD�`����C�n���O�Ψӽm���k
���A�A�i�H����(ci bag)�ݡC\n",
        ]));
        set("objects", ([
                "/d/shaolin/npc/mu-ren" : 5,
        ]));
	set("coor/x", -2740);
	set("coor/y", 120);
	set("coor/z", 170);
	setup();
}
void init()
{
      add_action("do_strike", "da");
      add_action("do_finger", "ci");
}

int do_finger()
{
      object me;
      int qi_cost,c_exp,c_skill;
      me = this_player();
      c_exp=me->query("combat_exp");
      c_skill=me->query_skill("finger",1);
      qi_cost = 10;
      if (me->query("qi")>qi_cost)
      {
	   message_vision( "$N���������a�I�V�F�U�Aı�o���y�L�L���ǵh�C\n", me );
           if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<101))
           me->improve_skill("finger", (int)me->query_skill("finger", 1));
           me->receive_damage("qi", qi_cost );
      }
      else
	   me->unconcious();	
      return 1;
}

int do_strike()
{
      object me;
      int qi_cost,c_exp,c_skill;
      me = this_player();
      c_exp=me->query("combat_exp");
      c_skill=me->query_skill("strike",1);
      qi_cost = 10;
      if (me->query("qi")>qi_cost)
      {
	   message_vision( "$N�ۤF�@�Ӱ��B�A���x���V���֯ȥU�C\n", me );
           if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<101))
           me->improve_skill("strike", (int)me->query_skill("strike", 1));
           me->receive_damage("qi", qi_cost );
      }
      else
           me->unconcious();
      return 1;
}
