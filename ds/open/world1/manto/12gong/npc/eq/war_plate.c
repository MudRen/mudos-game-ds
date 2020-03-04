#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
    set_name(HIR"�Ԫ�§�g"NOR ,({ "war plate","plate","armor"}));
    set("long",@LONG
�i�ԯ��j���紵�ˤ��U�@�d�ӭȱo�q����⪺�Y�֩Ұ��������Z�A
�Z���W�L�Ʀ���������զ��F�_�����]���A������رa�۱a�ӵL�P��
�񪺫H���C
LONG);
    set_weight(5000);
    if ( clonep() )
        set_default_object(__FILE__);
    else
    {
        set("material", "leather");
        set("volume",4);
        set("unit", "��");
        set("value",15000);
    }
    set("limit_con",50);
    set("limit_lv",40);
    set("armor_prop/armor",54);
    set("armor_prop/shield",25);
    set("armor_prop/con", 5);
    set("armor_prop/str", 2);
    set("armor_prop/dex", -4);
    set("armor_prop/hit", 5);
    setup();
    call_out("receive_by_plate", 60);
}

void receive_by_plate()
{
    object me; 
    int effect;
    if( !this_object() ) return;
    me = environment(this_object());
    if( !me || !interactive(me) || me->query_temp("armor/armor") != this_object() ) {
         //�S���H�ϥΤ�
       call_out("receive_by_plate", 90); 
        return ;
    }
    effect = me->query("max_mp");
    if( me->query("mp") < effect*4/5 ) {
        me->receive_heal("mp", effect/18);
        message_vision("�q$N�����j���X�ӿ@�p���������A$n���K�a�l�F�X�f�A�I�k���w�t�P�]�]����F���֡C\n"NOR,this_object(), me);
        call_out("receive_by_plate", 45);
    } else call_out("receive_by_plate", 90);
}

