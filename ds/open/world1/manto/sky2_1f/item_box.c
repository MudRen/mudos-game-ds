#include <ansi.h>
#include <box.h>

inherit BOX;
inherit BOX_LOG;

//int do_put(object me,string arg);
int do_xput(object me, object obj, object dest, int func);

//
void show(string arg);
//

void create()
{
        set_name(HIM"�D��m���c"NOR,({ "item box", "box" }));
        set("unit", "��");
        set("long",@long

�@�ΨӫO�s���h�D�㪺�@�Ӥj�K�c�A�A�i�H��öQ���D���b�c�l
�@�̭��ӫO�s�Ϊ̬O�q�c�l�����X�A�Q�ϥΪ��D��C

  ��F��:  put [�F��] in item box
  ���F��:  get [�F��] from item box
  ���}�c�l:  open item box
  ���_�c�l:  close item box

  �o�ӽc�l���ۯS���\��:
         ** checkuse 'box or shelf's id' {-w|-l|-m}
         ** cleanup 'box or shelf's id' {get|put|all}
long
);
        set("unit", "��");
        set("cover_name", "�K�\\");
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        set_max_encumbrance(999999);
        set_max_capacity(800);
        set("access_log",1);
        set("demand_level", 3);
        set("club_id", "sky");
        setup();
        set_cover(COVER_CLOSED);
}

void init()
{
        add_action("do_put", "put");
}

int do_put(string arg)
{
        string target, item;

        object me, obj, dest, *inv, obj2;
        int i, amount, active=0;
        me = this_player();

        if(!arg) return notify_fail("�A�n�N����F���i���̡S\n");

        if( sscanf(arg, "%s in %s", item, target)!=2 )
                return notify_fail("�A�n�񤰻�F��S\n");
        if( target == "weapon box" || target == "equip box" || target == "item box" || target == "box" )
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
                        return notify_fail("�e��������e���̡C\n");
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
        object tmp;
        int other_tar = 0;
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
        if( !obj->can_move(dest)) return notify_fail("�A�S����k��"+obj->query("name")+"��i"+dest->query("name")+"�̡C\n");
        if( obj->query("secured") ) return notify_fail("�A�L�k�N�]�w���O�s���A�����~��i�e����.\n");
        if( func && dest == this_object() ) {
                if( (obj->query("skill_type") || obj->is_weapon()) && objectp(tmp = load_object("/open/world1/manto/map_1_11.c")) )
                {
                        if( tmp != environment(this_object()) )
                        {
                                write("�۰ʱN "+ obj->name(1) + "������Z�����C\n");
                                other_tar=1;
                                dest = tmp;
                        }
                }
                else if( ( obj->query("armor_type") || obj->is_armor() ) && objectp(tmp = load_object("/open/world1/manto/map_3_11.c")) )
                {
                        if( tmp != environment(this_object()) )
                        {
                                write("�۰ʱN "+ obj->name(1) + "�����쨾�㶡�C\n");
                                other_tar=2;
                                dest = tmp;
                        }
                }
                else if( objectp(tmp = load_object("/open/world1/manto/map_5_11.c")) )
                {
                        if( tmp != environment(this_object()) )
                        {
                                write("�۰ʱN "+ obj->name(1) + "������D�㶡�C\n");
                                other_tar=3;
                                dest = tmp;
                        }
                }
        }
        if( obj->move(dest) )
        {
                if( other_tar == 0 )
                        message_vision( sprintf("$N�N�@%s%s��i%s�C\n",
                                obj->query("unit"), obj->name(), dest->name()),
                                me );
                if( dest->query("access_log") ) log_file("access_log",sprintf("[%s] %s put %s in %s\n",ctime(time()),me->name_id(1),obj->name(),dest->short()));
                return 1;
        }
        else return 0;
}

void show(string arg)
{
        tell_room(environment(this_object()),arg + "\n", ({ }));
        return;
}
