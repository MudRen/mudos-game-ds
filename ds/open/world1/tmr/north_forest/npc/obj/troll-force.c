#include <ansi.h>
inherit ITEM;

void create()
{
        set_name( HBK "���]���O" NOR , ({ "troll-force symbol", "symbol", "_TROLL_FORCE_"}));
        set("long", "�o�O�@�ӥѥ��]���Y�Φ�G�������ťۡA�㦳�A�ͯ�O�A��v¡�˶աC\n");
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("value", 0);
                set("no_give", 1);
                set("no_put",1);
                set("no_sell", 1);
        }
        setup();
        call_out("receive_by_stone", 60);
}

void receive_by_stone()
{
        object me = environment(this_object());
          int p_hp;

        if( !this_object() || !me ) return;
        if( interactive(me) )
        {
                p_hp = me->query("max_hp");
                  if( me->query("hp") < p_hp *8/10 )
                {
                       me->receive_heal("hp", p_hp/27);
                        message_vision( YEL "$N"YEL"�W���Ť������o�G�A$n���W���˶ն}�l��_�F�C\n"NOR, this_object(), me);
                        add_temp("times",1);
                          if(query_temp("times") > 2500) {
                                message_vision( HBK "$N"HBK"���Ť�w�g���h�ĥΤF�A�H�Y�]�Ƨ@�@�ﯻ���A�����F�C"NOR, this_object(), me);
                                destruct(this_object());
                        }
                }
                else
                {
                        message_vision( "$N�p�p���_�ʤ@�U�A���O�S���o�ͤ���ơC\n", this_object());
                }
        }
        call_out("receive_by_stone", 35);
}

int query_unique() { return 1; }  // ���� daily eq
