#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("Ų�w���b"NOR, ({ "identify scroll", "scroll" }));
    set_weight(1);
    set("long", "�j���өҳc�檺�ǽŦⱲ�b�A�֦��@�ǯS�O����O�C\n"
                "����Ψ�Ų�w(ident)��L���~�C\n");
    set("unit", "��");
    set("value", 100);
    setup();
}

int query_autoload() { return 1; }

void init()
{
    add_action("do_ident", "ident");
}

int do_ident(string arg)
{
    object ob, me;
    string target;
    mapping apply;

    me = this_player();

    if( me->is_busy() ) return notify_fail("�ʧ@�٨S�����A����Ų�w�C\n");

    if( !arg ) return notify_fail("�A�nŲ�w����F��?\n");
    if( sscanf(arg, "%s", target) == 1 ) target = arg;

    ob = find_object(target);
    if( !ob ) ob = present(target, me);
    if( !ob ) ob = present(target, environment(me));
    if( !ob ) return notify_fail("�o�̨S���A�nŲ�w���F��C\n");
    if( environment(this_object()) != me ) return notify_fail("���b���b�A���W�C\n");
    if( ob->id("past_money") ) return notify_fail("�N�w�g�O���F�٭nŲ�w����F�F�C\n");
    if( ob->is_character() || ob->is_corpse() ) return notify_fail("�u��Ų�w���~�����F��C\n");

    message_vision(HIW"\n$N�N"NOR+ob->query("name")+"("+ob->query("id")+")"HIW"�\\��b���}��$n�W�A���G�B�{�X�F�@�ǪF��...\n\n"NOR, me, this_object());

    printf("Ų�w�W�١G%s�B���q�G%d\n�����G%d\n", ob->query("name"), ob->query_weight(), ob->query("value"));
    switch( ob->query_autoload() ) {
        case 0: printf("���~�O�s�G"HIR"�_\n"NOR); break;
        case 1: printf("���~�O�s�G"HIY"�i\n"NOR); break;
    }
    if( ob->query("heal") ) {
        string prop;
        mixed value;
        printf("���O�G�ī~\n"NOR);

        apply = ob->query("heal");
        write("�S�ʡG");
        foreach(prop, value in apply) {
            if( prop == "show_damage" ) continue;
            printf("%s+%O ", prop, value);
        }
        printf("\n\n");
    } else if( ob->query("skill_type") ) {
        string prop;
        mixed value;
        printf("�Z���¤O�G%d�B�Z�����O�G%s\n���ŭ���G%d\n"NOR, ob->query("weapon_prop/damage"), to_chinese(ob->query("skill_type")), ob->query("limit_level"));
        apply = ob->query("weapon_prop");
        write("�S�ʡG");
        foreach(prop, value in apply) {
            if( prop == "damage" ) continue;
            if( value == 0 ) continue;
            if( prop == "show_damage" ) continue;
            printf("%s:%O ", prop, value);
        }
        printf("\n\n");
    } else if( ob->query("armor_type") ) {
        string prop;
        mixed value;
        printf("���m��O�G%d�B�������O�G%s\n���ŭ���G%d\n"NOR, ob->query("armor_prop/armor"), to_chinese(ob->query("armor_type")), ob->query("limit_lv"));
        apply = ob->query("armor_prop");
        write("�S�ʡG");
        foreach(prop, value in apply) {
            if( prop == "armor" ) continue;
            if( prop == "show_damage" ) continue;
            if( value == 0 ) continue;
            printf("%s:%O ", prop, value);
        }
        printf("\n\n");
    } else {
        printf("��L��T�ȮɵL�kŲ�w�C\n\n"NOR);
    }
    if( !wizardp(me)) me->start_busy(3);
    destruct(this_object());
    return 1;
}
