#include <room.h>
#include <ansi.h>
inherit ROOM;
//int do_cput(string arg);
int do_xput(object me, object obj, object dest, int func);
void create()
{
 set("short",HIR"���@���]"NOR);
 set("long", @LONG
�A�Ө�F�@�Ӥ�����D���}�ޤ���, ���䴡�F�@��C�T, �i�O�A
�o�ݤ���C�b��B. �A�J�Ӫ��[��F�@�}�l, �o�{�۾��W����F����:

		��   ��   �W   ��
		�n   �C   �b   ��
		�F   �D   ��   �l
		��   ��   ��   ��
		�E   ��   �B   ��
		�d   ��   ��   �L	��
		��   ��   ��   ��       �@
					��
		
					�D

�u�O���g�Ʀۤj���å�! �����D�L�O�_�٬��b�o�@�W�O?
LONG
    ); 
 set("exits", (["wiz": "/d/wiz/hall1"]));
 set("objects", ([ "/open/world1/acme/area/sky/item/weapon_shelf" :1,
		   "/open/world1/acme/area/sky/item/equip_shelf" :1,
		   "/open/world1/acme/area/sky/item/item_shelf" :1, ]));
 set("light",1);
 set("valid_startroom",1);  
 setup();
 call_other("/obj/board/programming_b","???");
}                   
void init()
{
//    add_action("no_put","put");
    add_action("do_put","put");
}
int no_put(string arg)
{
  write("�o�䤣��� put ��, �n��F��Ч�� cput..!\n");
  return 1;
}

int do_put(string arg)
{
        string target, item;

	object me,obj,dest,*inv,obj2;
        int i, amount,active=0;
	me=this_player();


	if(!arg) return notify_fail("�A�n�N����F���i����?\n");
        if( sscanf(arg, "%s in %s", item, target)!=2 )
                return notify_fail("�A�n�񤰻�F��S\n");
        if( target == "shelf" || target == "equip shelf" || target == "weapon shelf" || target == "item shelf")
		active = 1;
        dest = present(target, me);
        if( !dest || living(dest) ) dest = present(target, environment(me));
        if( !dest || living(dest) ) return notify_fail("�o�̨S���o�˪F��C\n");
        if( dest->is_box() )
        {
                if(!dest->can_access_box()) return notify_fail("�A���������}"+dest->name()+"�~���F��i�h�C\n");

        }
        if(sscanf(item, "%d %s", amount, item)==2)
        {
                if( !objectp(obj = present(item, me)) )
                        return notify_fail("�A���W�S���o�˪F��C\n");
                if( obj==dest ) return notify_fail("�ӷ��M�ت�����O�ۦP���F��!\n");
                if( !obj->query_amount() )
                        return notify_fail( obj->name() + "����Q���}�C\n");
                if( dest->query_max_encumbrance() < 1) return notify_fail(dest->query("name")+"�ä��O�@�Ӯe���C\n");
                if( obj->query_max_encumbrance() && !obj->query("no_get"))
                        return notify_fail( "�e��������e���̡C\n");
                if( obj->query("no_drop") )
                        return notify_fail( obj->name() + "����Q���C\n");
                if( amount < 1 )
                        return notify_fail("�F�誺�ƶq�ܤ֬O�@�ӡC\n");
                if( amount > obj->query_amount() )
                        return notify_fail("�A�S������h��" + obj->name() + "�C\n");
                else if( amount == (int)obj->query_amount() )
                        return do_xput(me, obj, dest, active);
                else {
                        obj2 = new(base_name(obj));
                        obj2->set_amount(amount);
                        if(!obj2->can_move(dest))
                        {
                                destruct(obj2);
                                return notify_fail("�A�S����k��"+obj->query("name")+"��i"+dest->query("name")+"�̡C\n");
                        }
                        obj->set_amount( (int)obj->query_amount() - amount );
                        return do_xput(me, obj2, dest, active);
                }
        }

        if(item=="all") {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                        if( inv[i] != dest ) do_xput(me, inv[i], dest, active);
                write("Ok.\n");
                return 1;
        }

        if(!objectp(obj = present(item, me)))
                return notify_fail("�A���W�S���o�˪F��C\n");
        return do_xput(me, obj, dest, active);
}

int do_xput(object me, object obj, object dest, int func)
{
        mixed no_put;
        if( obj==dest ) return notify_fail("�ӷ��M�ت�����O�ۦP���F��!\n");
        if( dest->query_max_encumbrance() < 1) return notify_fail(dest->query("name")+"�ä��O�@�Ӯ
e���C\n");
        if( obj->query_max_encumbrance()  && !obj->query("no_get"))
                        return notify_fail( "�e��������e���̡C\n");
        if( obj->query("no_drop") )
                        return notify_fail( obj->name() + "����Q���C\n");
        if( no_put = obj->query("no_drop"))
        {
                if(stringp(no_put)) return notify_fail( no_put+"\n");
                return notify_fail( "�A�L�k��"+obj->name()+"��i���̡C\n");
        }
        if( obj->query_temp("riden") ) return notify_fail("�A���b�M�ۭC!\n");
        if(!obj->can_move(dest)) return notify_fail("�A�S����k��"+obj->query("name")+"��i"+dest->query("name")+"�̡C\n");
	if( func ) {
		if( obj->query("skill_type") )
            dest = present("weapon shelf",environment(me));
		else if(obj->query("armor_type") )
            dest = present("equip shelf",environment(me));
        else dest = present("item shelf",environment(me));
	}
        if( obj->move(dest) )
        {
                message_vision( sprintf("$N�N�@%s%s��i%s�C\n",
                        obj->query("unit"), obj->name(), dest->name()),
                        me );
//                message_vision("\nFUNC: "+func+"\n",me);
                if(dest->query("access_log")) log_file("access_log",sprintf("[%s] %s put %s in %s\n",ctime(time()),me->name_id(1),obj->name(),dest->short()));
                return 1;
        }
        else return 0;
}
