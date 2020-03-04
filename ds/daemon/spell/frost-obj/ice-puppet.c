#include <ansi.h>

inherit ITEM;

void create()
{
        // �N�v ITEM�A�H�uCOMPENSATORY_ITEM�v���ѧO
        set_name(HIW"�B�����w" NOR, ({ "ice puppet","ice-puppet","puppet", "COMPENSATORY_ITEM"}) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",@LONG
�@���������v���B�����w�A���o�۵����H��C�o�ӦB�����w��e��
�O�@�ӭ��ص��N�A�e���u���ܵL�H�_�[���M�h���k�A�����ɥߡA�z
�����֤��z�X�L���j�����C�M�������l�{�ʵ۲`���i��������
�M���~�A���C�賣�b�V�A�ɶD�۬Y�����H���몺�Ⱦ��C
�A�i�H�d��(verify)�o�ӳ��w�ٯ�Ө��h�ֶˮ`�C
LONG
);
                set("unit", "��");
                set("no_give",1);
        set("value",1);
                set("no_get",1);
                set("no_put",1);
        }
       setup();
}

void do_dest() {
        destruct(this_object());
}

void init()
{
        if( !living(environment(this_object())) ) {
              //  message_vision("�S�X�U�l$N�N�ĸѦ��@�y���F�C\n", this_object());
                call_out( "do_dest", 1);
                return;
        }
        if( !environment(this_object())->query_spell("ice-puppet") ) {
                // �S���ǹL ice-puppet
                set("hp", 0);
                return;
        }
        add_action("do_check","verify");
}

int do_check() {
        tell_object(this_player(), "�B�����w�٥i�H�Ө�"+query("hp")+"�I���ˮ`�C\n");
        return 1;
}

void update_pet(object me) {
        // �i�H�N�v����
        set("hp", me->query_int()*5
                  + me->query_spell("ice-puppet")*5
                + me->query_wit()*100
        );
}

// Don't Clone
int query_unique() { return 1; }


