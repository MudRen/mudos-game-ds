#include <ansi2.h>
#include <armor.h>
inherit CLOTH;

void create()
{
    set_name(HIM"����"HIY"�q��"NOR, ({ "unknown stone", "stone" }));
    set_weight(1000);
    set("long", "�H�U���ثe�ҵo�{����q�ϥΤ�k�G\n"
                "�~�w�w�w�w�s�w�w�w�w�w�w�w�w�s�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n"
                "�x"HIR"�������"NOR"�xfk <A> with <B> �x���D�H������ͪ����ۧ����C�x\n"
                "�x"HIM"����]��"NOR"�xate <A>         �x�N�D���a���F��]���C        �x\n"
                "�x"HIW+BLK"�¦⦺�I"NOR"�xhack <A>        �x�ϥΦ����I�M�����ͪ��C      �x\n"
                "�x"HIW"�զ�v¡"NOR"�xheal <A>        �x�ֳt�^�_�ؼФH�����ͩR�C    �x\n"
                "���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n\n");
    if( clonep() ) set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("value", 0);
    }
    set("limit_lv",80);
    set("armor_prop/armor", 300);
    set("armor_prop/shield", 300);

    set("armor_prop/bar", 10);
    set("armor_prop/sou", 10);
    set("armor_prop/tec", 10);
    set("armor_prop/bio", 10);
    set("armor_prop/wit", 10);
    set("armor_prop/show_damage", 1);
    setup();
}

int query_autoload() { return 1; }

void init()
{
    add_action("do_fk", "fk");
    add_action("do_eat", "ate");
    add_action("do_hack", "hack");
    add_action("do_heal", "heal");
}
int do_fk(string arg)
{
    string str, npc;
    object ob, me, obj;

    me = this_player();

    seteuid(getuid());
    if( !arg || sscanf(arg, "%s with %s", str, npc) != 2 )
        return notify_fail("���O�榡�Rfk <Mob> with <Mob>\n");

    if( !(ob = present(str, environment(me))) )
        return notify_fail(HIR"�o�̨S�� "NOR+str+HIR" �o���H���C\n"NOR);

    if( !(obj = present(npc, environment(me))) )
        return notify_fail(HIR"�o�̨S��"NOR+npc+HIR"�o���H���C\n"NOR);

    if( !ob->is_character() || !obj->is_character() )
        return notify_fail(HIY"��Ӫ��󤤦��䤤���@�L�k����R�O�C\n"NOR);

    if( userp(ob) || userp(obj) )
        return notify_fail(HIY"�Q�R�O�����褣�i�O���a�C\n"NOR);

    message_vision(HIR"$N�o�X���O��"NOR+ob->name()+HIR"�D�ʧ���"NOR+obj->name()+HIR"�I\n"NOR, me);
    ob->kill_ob(obj);
    obj->kill_ob(ob);
    return 1;
}

int do_eat(string arg)
{
    string target;
    object obj, me;

    me = this_player();

    seteuid(geteuid(this_player(1)));
    if( !arg ) return notify_fail("���O�榡 : ate <���󤧦W�٩��ɦW>\n" );

    if( sscanf(arg, "%s", target) == 1 ) target = arg;

    obj = find_object(target);
    if( !obj ) obj = present(target, me);
    if( !obj ) obj = present(target, environment(me));
    if( !obj ) obj = find_object( resolve_path(me->query("cwd"), target) );
    if( !obj ) return notify_fail("�n���Ӿj�F...�S�ݨ�o�˪��~�C\n");

    if( (userp(obj) && !wizardp(obj)) || obj->query("userp") > 0 )
        return notify_fail(HIB"���a�����H�K�Q�A���Y���C\n"NOR);

    message_vision(HIW"$N"HIM"�ϥX"HIY"�y"HIC"�]�]�u�t"HIY"�z"HIM"�@�f���f����"NOR"$n"HIM"���Y���F�C\n"NOR, me, obj);
    destruct(obj);

    RACE_D( me->query("race") )->reset_attribute( me );
    if( obj ) write("�o�˪F����G�]�]�u�t�]�Y�����C\n");
    else write("Ok.\n");
    return 1;
}
int do_hack(string arg)
{
    string npc;
    object obj, me;

    me = this_player();

    seteuid(geteuid(this_player(1)));
    if( !arg || sscanf(arg, "%s", npc) != 1 )
        return notify_fail("���O�榡 : hack <Mob Name>\n");

    if( !(obj = present(npc, environment(me))) )
        return notify_fail(" "NOR+npc+HIR" �S���b�o�̡A��Ů�ܡH\n"NOR);

    if( !obj->is_character() || obj->is_corpse() )
        return notify_fail(HIB"�o�˪F��S�ͩR�A�奦�]�S�ΡC\n"NOR);

    if( (userp(obj) && wizardp(obj)) || obj->query("userp") > 0 )

        return notify_fail(HIB"����ì�H���Y�ǡI\n"NOR);

    if( environment(me)==environment(obj) ) {
        obj->set_temp("last_damage_from", me);
        message_vision(HIR"$N"HIR"���˪����_"HIW+BLK"�����I�M"HIR"...����N��U�F"NOR"$n"HIR"�����U...\n"NOR, me, obj);
        message_vision(HIR"�u��"NOR"$n"HIR"�����l���M������ʼQ�X�Ѿl����G...\n"NOR, me, obj);
        obj->die();
    }
    if(obj) write("�����I�M�~�M���F�F�H�ڪ��Ѫ��I\n");
    else write("Ok.\n");
    return 1;
}
int do_heal(string arg)
{
    string npc;
    object obj, me;

    me = this_player();

    seteuid(geteuid(this_player(1)));

    // ���w�H�����b�N�P�w�O�ϥΪ�
    if( !arg || sscanf(arg, "%s", npc) != 1 ) npc = me->query("id");
    if( !( obj = present(npc, environment(me)) ) ) obj = me;

    if( !obj->is_character() || obj->is_corpse() )
        return notify_fail(HIG"�o�˪F��S�ͩR�A�N�����L�v���]���|�ܦ��ͪ��C\n"NOR);

    if( obj == me ) {
        message_vision(HIW"$N�O���a��_�F�j�Ѫ��G�y�A�@�}�ŷx���ե��ֳtŢ�n�ۧA�ۤv������...\n"NOR, me);
        tell_object(obj,HIY"�A���������ե��[���A�w�g�^�_��̨Ϊ��A�F�C\n"NOR);
    } else {
        message_vision(HIW"$N�O���a��_�F�j�Ѫ��G�y�A�@�}�ŷx���ե��ֳtŢ�n��$n������...\n"NOR, me, obj);
        tell_object(obj,HIY"�A���������ե��[���A�w�g�^�_��̨Ϊ��A�F�C\n"NOR);
    }
    // �Ҧ�����ˮ`�Ѱ�
    obj->receive_curing("left_arm", 100);
    obj->receive_curing("left_leg", 100);
    obj->receive_curing("right_arm", 100);
    obj->receive_curing("right_leg", 100);
    obj->receive_curing("body", 100);
    obj->receive_curing("head", 100);

    // ��O�^��̨Ϊ��A
    obj->receive_heal("hp", obj->query("max_hp"));
    obj->receive_heal("ap", obj->query("max_ap"));
    obj->receive_heal("mp", obj->query("max_mp"));

    return 1;
}
