#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�Ŧa");
        set("long", @LONG
�A���b�@���۪d�Ŧa�W�A�|�P��¶�L��A�u���Ŧa����ߤF���֤��
���H�A�E�Ƥ��U�A�����Q�Ө㤧�ơA�Ҧ��@�릨�H�j�p�A���G�O���H�m�\
�����Ϊ��C�b�Ŧa�譺����²�����۪O�ΡA�������~�A�ɬҪ����A�F
�L�H��C
�p�G�A�Q�n�i�h�۪O�ǡA�i�H��enter house�C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	  "northeast" : __DIR__"vroad5",
	]));
        set("item_desc", ([
        "house" : "�@���ݨӤQ��������p�۫�, �γ\\�A�i�H�i�h�ݬݡC\n",
        "�۪O��" : "�@���ݨӤQ��������p�۫�, �γ\\�A�i�H�i�h�ݬݡC\n",
        ]));
	set("objects",([
		//__DIR__"npc/leewuda_13":1,
		//__DIR__"npc/leewuder_12":1,
		__DIR__"npc/leecharfan_22":1,
	]));
	set("outdoors","land");
        set("no_clean_up", 0);

        setup();
}

void init()
{
	add_action("do_enter","enter");
	add_action("do_practice","practice");
}

int do_enter(string arg)
{
	object me;
	me=this_player();

	if (arg != "�۪O��" && arg !="house" )
		return 0;
	else 
	{
	message_vision("$N���}�F�۪O�Ϊ���O���A���F�i�h�C\n",me);
	me->move(__DIR__"s_house");
      tell_room(environment(me),me->query("name")+"���}�F�۪O�Ϊ���O���A���F�i�ӡC\n",me);
	return 1;
	}
}

int do_practice(string arg)
{
	object me,weapon;	
	me=this_player();

	if(!arg) return 0;
	if(!me->query_skill("da-fork") ) return 0;
	if(arg!="da-fork") return notify_fail("�A�u��m�j�j�Z(da-fork)�C\n");

	weapon=me->query_temp("weapon");
	if(!weapon)	return notify_fail("�A�o���K�j�~��m�j�j�Z�C\n");
	if(weapon->query("skill_type")!="fork") 
		return notify_fail("�A�o���K�j�~��m�j�j�Z�C\n");
         if(me->query_skill("da-fork")>9 )  return notify_fail("�A���j�j�Z�w���p���F�A�b���m�j�w�L�q�F�C\n");
	if(me->query("ap") <10) 
		return notify_fail("�A�����l�����A����m�j�j�Z�C�C\n");

     message_vision("$N���_�⤤��"+weapon->query("name")+NOR"��۰��H�F��@�j�A���@�j�a�m�F�ۤj�j�Z���򥻩ۦ��C\n",me);
	me->receive_damage("ap",10);

	if(me->query("sk/da-fork") )
		me->add("sk/da-fork",random(me->query_int()) );
	else
		me->set("sk/da-fork",random(me->query_int()) );

      if(me->query("sk/da-fork" )>5000)
	{
		tell_object(me,HIY "�g�L�@�f�W�m�A�A���j�j�Z�����F�C\n" NOR);
        me->delete("sk/da-fork");
          me->set_skill("da-fork",10);
	}
	return 1;

}



