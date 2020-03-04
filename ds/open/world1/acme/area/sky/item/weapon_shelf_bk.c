#include <ansi.h>
inherit ITEM;
inherit BOX_LOG;
//int do_put(object me,string arg);
int do_xput(object me, object obj, object dest, int func);
void create()
{
    set_name(HIG"�Z�����C�["NOR,({"weapon shelf","shelf"}));
        set("unit", "��");
        set("long",@long

  �@�ӥΨө�m�O�s���h�Z�����K�[�C�A�i�H��öQ���Z����b�[
  �W�O�s�άO�q�[�l�����X�A�ҳ߷R���Z���C

  ��F��: put [�F��] in weapon shelf
  ���F��: get [�F��] from weapon shelf

  �o�Ӭ[�l���ۯS���\��:
         ** checkuse 'box or shelf's id' {-w|-l|-m}
         ** cleanup 'box or shelf's id' {get|put|all}

long
);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        set_max_encumbrance(999999);  
        set_max_capacity(90); // jangshow
        set("club_id", "sky");
        set("demand_level", 3);
        setup();
}

void init()
{
        add_action("do_put", "put");
}

int do_put(string arg)
{
        string target, item;

        object me, obj, dest, *inv, obj2;
        int i, amount,active=0;
        me = this_player();

        if(!arg) return notify_fail("�A�n�N����F���i���̡S\n");

        if( sscanf(arg, "%s in %s", item, target)!=2 )
                return notify_fail("�A�n�񤰻�F��S\n");
        if( target == "shelf" || target == "equip shelf" || target == "weapon shelf" || target ==
            "item shelf" || target == "shelf 1" || target == "shelf 2" || target == "shelf 3" )
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
        if( obj->query("equipped") ) return notify_fail( obj->name() + "���Q�A�˳Ƶ�, ������e���̡C\n");
        if( dest->query_max_encumbrance() < 1) return notify_fail(dest->query("name")+"�ä��O�@�Ӯe���C\n");
        if( obj->query_max_encumbrance()  && !obj->query("no_get"))
                        return notify_fail( "�e��������e���̡C\n");
  if( obj->query("no_put")) return notify_fail("�o�F�褣����e���̡C\n");  // add by wilfred
        if( obj->query("no_drop") )
                        return notify_fail( obj->name() + "����Q���C\n");
        if( no_put = obj->query("no_drop"))
        {
                if(stringp(no_put)) return notify_fail( no_put+"\n");
                return notify_fail( "�A�L�k��"+obj->name()+"��i���̡C\n");
        }
        if( obj->query_temp("riden") ) return notify_fail("�A���b�M�ۭC!\n");
        if(!obj->can_move(dest)) return notify_fail("�A�S����k��"+obj->query("name")+"��i"+dest->query("name")+"�̡C\n");
        if( obj->query("secured") ) return notify_fail( obj->name() +"�Q�A�]�w���O�s���A, ������e�����C\n");
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
                if(dest->query("access_log")) log_file("access_log",sprintf("[%s] %s put %s in %s\n",ctime(time()),me->name_id(1),obj->name(),dest->short()));
                dest->log_put(me, obj);
                return 1;
        }
        else return 0;
}

