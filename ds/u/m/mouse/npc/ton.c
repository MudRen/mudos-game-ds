#include <ansi.h>
inherit NPC;

void create()
{
    set_name(HIY"�q���Q��"NOR,({"tonbeli king", "tonbeli", "king"}) );
    set("long","�����M�����ͪ��A�]���S�Q�٩I���u��M�ǡv\n"
               "�e�̬O�t�S�Կ�񪺭����A�q�X�ͨ즺�`�����F�u�@���a�C\n"
               "���e�o����������{�{�A���Y���ӫa�A���ӬO�e�̪�����F�C\n");
    set("race", "ogre");
    set("unit", "��");
    set("title", HBK"�t�S�Կ��"NOR);
    set("age", 1000 + random(5000));
    set("level", 70);
    set("limbs", ({ "�Y��", "����","�ݤf","�I��", "�u�L", "�u��"}) );
    set("chat_chance", 30);
    set("chat_msg", ({
        (: random_move :),
    }) );
    set("max_hp", 30000 + random(20000));
    set("max_ap", 10000 + random(10000));
    set("max_mp", 10000 + random(10000));
    setup();
    carry_object(__DIR__"obj/meat");
    carry_object(__DIR__"obj/meat");
    carry_object(__DIR__"obj/meat");
    carry_object(__DIR__"obj/meat");
    carry_object(__DIR__"obj/meat");
}

int filter(object inv)
{
    if( inv->id("quest_ob") ) return 0;    // notebook
    if( inv->id("mail_ob") ) return 0;     // mailbox
    if( inv->id("undead_item") ) return 0; // doll
    if( inv->id("past_money") ) return 0;  // money
    return 1;
}

int special_attack(object me, object target, int hitchance)
{
    object *inv;
    object item;
    int i, j, damage;

    string *msg = ({ "�Y��", "�I��", "�y��", "�L��", "���", "�}��" });

    inv = all_inventory(target);
    if( !sizeof(inv) ) return 0;

    inv = filter_array(inv, (:filter:) );
    i = random(8)+3;

    if( !me || !target ) return 0;
    if( target->is_busy() ) return 0;
    if( random(100) < 25 ) {
        message_vision("\n$N"HBK"�H��l��X"+chinese_number(i)+"��U����"NOR"$n"HBK"�Y�W�{�h...\n\n"NOR, me, target);
        for(j=i;j>0;j--) {
            if( !sizeof(inv) ) {
                message_vision("���O$N�l�ꥢ�ѤF�A����Ƴ��S�o�͡C\n\n"NOR, me);
                return 0;
            }
            // ��o item
            item = new( base_name(inv[random(sizeof(inv))]) );
            if( !objectp(item) ) return 0;

            damage = item->query_weight();

            if( item->query("weapon_prop") ) {
                if( item->query("weapon_prop/bio") >= 1 &&  item->query("weapon_prop/wit") >= 1 ) damage = (COMBAT_D->Merits_damage(me, target, damage/2, "bio") + COMBAT_D->Merits_damage(me, target, damage/2, "wit"));
                else if( item->query("weapon_prop/bio") >= 1 ) damage = COMBAT_D->Merits_damage(me, target, damage, "bio");
                else if( item->query("weapon_prop/wit") >= 1 ) damage = COMBAT_D->Merits_damage(me, target, damage, "wit");
            }
            if( item->query("armor_prop") ) {
                if( item->query("armor_prop/bio") >= 1 &&  item->query("armor_prop/wit") >= 1 ) damage = (COMBAT_D->Merits_damage(me, target, damage/2, "bio") + COMBAT_D->Merits_damage(me, target, damage/2, "wit"));
                else if( item->query("armor_prop/bio") >= 1 ) damage = COMBAT_D->Merits_damage(me, target, damage, "bio");
                else if( item->query("armor_prop/wit") >= 1 ) damage = COMBAT_D->Merits_damage(me, target, damage, "wit");
            }
            damage -= target->query_armor()/2 + random(target->query_armor()/2);

            if( damage < 1 ) {
                message_vision("$n"HIY"�H�p�^���զV$N�q�g�ӦܡI�o�Q$N�H�O�ϤO�D�ƸѤF�����C\n"NOR, target, item);
            COMBAT_D->report_status(target);
                continue;
            }
            if( damage > 600 ) damage = 600 + random(200);
            else damage -= random(50);

            target->receive_damage("hp", damage);
            message_vision(HIR"�U�ةU���Ƥ����ɦa�q���żY���A$N���V�Q"NOR"$n"HIR"�����F"+msg[random(sizeof(msg))]+"�I"HIY" ("+damage+")\n"NOR, target, item);
            COMBAT_D->report_status(target);
        }
        message_vision(NOR"\n"NOR, me);
        target->start_busy(1);
        me->start_busy(2);
    }
    return 0;
}
