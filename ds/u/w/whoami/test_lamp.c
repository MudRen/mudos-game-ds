#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"��֤ѿO"NOR, ({ "wish lamp","lamp" }) );
        set_weight(600);
        set_max_capacity(2000);
        set_max_encumbrance(2000);      // ���]�@�i�ȥu���@�J
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�f");
                set("long",@LONG
�ѿO�S�٬��թ��O�A�۶Ǭ��T��Ѹ��G���o���A�]�Q���{������y���l��
�A�_��O���F�ǻ��T�����ΡA���ثe�q�`�h�Q���`�y��ֳ\�@(wish)���u��C
�A�i�H�\���@�榳�U�C�o�ǡA�@���u���ܤ@���@��G
    1. wish exp   [�A�Q�n�o�쪺�g��ȼƥ�]
    2. wish pop   [�A�Q�n�o�쪺�n��ƥ�]
    3. wish art   [�A�Q�n�o�쪺�԰����N�ƥ�]
    4. wish money [�A�Q�n�o�쪺�����ƥ�]

    �S�O���G�C�@�ӤѿO���� (�O�o�~��)/10000 �����v��o�@�Ӥ��d�����C

�b�A�\���@����A�N�n��J�������O�o�A����N���I�U(ignite)�ѿO�A���ѿO��
�찪�ťh�A�p�G�ন�\�ɪšA�A�N���{�A���@��C
�A�i�H�ϥΡuoil�v���O���˵��ثe�ѿO���񦳦h�ֿO�o�C
LONG
);
                set("value", 99);
               }
        setup();
}
void init()
{
        add_action("do_wish","wish");
        add_action("do_light","ignite");
        add_action("do_oil","oil");
}
int do_wish(string arg)
{
    object me;
        string type, wish;
        int amount;
        me = this_player();
        if(!arg || sscanf(arg, "%s %d", type, amount) != 2 || amount < 1)
                return notify_fail("�A�Q�n�\\�����@�H\n");
        if( query("wish_type") )
                return notify_fail("�A�o�ѿO�w�g�\\�L�@��C\n");
        switch(type) {
                case "exp":
                        wish = "�g��� "+amount+"�I";
                break;
                case "pop":
                        wish = "�n�� "+amount+"�I";
                break;
                case "art":
                        wish = "�԰����N "+amount+"�I";
                break;
                case "money":
                        wish = "" + amount+"�T�ɪ�";
                break;
                default:
                        wish = type;
        }
        message_vision( CYN"$N�ۤ߸۷N�a��ۤѿO�\\�U�u" + wish + "�v���@��C\n" NOR,me);
        set("name", HIY"��֤ѿO [" + wish + "]" NOR);
        set("wish",wish);
        set("wish_type", type); 
        set("wish_amount",amount);
    return 1;
}
void light2(object me) {
        string msg;
        int s1,s2;
        s1 = 1;       
//        s2 = isSuccess2();      // �U�U��
        if( s1 || s2 ) {
                switch(query("wish_type") ) {
                case "exp": 
                        me->add("exp", query("wish_amount"));
                break;
                case "pop": 
                        me->add("popularity", query("wish_amount"));
                break;
                case "art": 
                        me->add("war_art", query("wish_amount"));
                break;
                case "money":   // �̮e�����\
                        me->add("bank/past", query("wish_amount"));
                break;
                }
                if( s1 = random(2) ) 
                        msg = HIC"\n\t�u��"+me->name()+HIC"�� " + name() +HIC" �a�۳\\�U���@��A�ɨ�ܰ��ܰ����ѻڡC\n"NOR;
                else 
                        msg = HIC"\n\t�u��"+me->name()+HIC"�� " + name() +HIC" �a�۳\\�U���@��A�{�p"HIR"�ۤ�"HIC"�@�ˡA�b�ѪŤ��Ƭ��@��"HIR"���y"HIC"�I�I\n"NOR;

                // �S�O���Gdoll
//              if( getOils() > random(10000) ) {
//                      new("/open/world1/tmr/game/2007_light/wish_lamp_doll.c")->move(me);
//                      msg += HIG"\n\t\t�u���@�Ӥp���i�R���ѿO�����q�ѻڽw�w���� "+me->name()+HIG"���⤤�C\n"NOR;
//                }
        message("system",  msg, users() );
        } else {
            message_vision(HIM "�i��$n"HIM"�n�n�ױסA�@�U�l�N�����줣���D���...\n"NOR, me, this_object() );
        }
        destruct(this_object());
}

int do_light(string arg)
{
    object me;
        me = this_player();
        if( !arg || arg != "lamp" )
                return notify_fail("�A�Q�n�I�U����H\n");
        if( query("ignite") )
                return notify_fail("�o�ѿO�w�g�I�U�A���b�ɪŤ��C\n");
        if( !query("wish_type") )
                return notify_fail("�A�o�ѿO�٨S���\\�L�@�C\n");
//        if( getOil() < 1 )
//                return notify_fail("�o�ѿO���S���O�o�A�L�k�I�U�C\n");

    message_vision(HIC"$N�I�U$n"HIC"�����O�o�A�u��$n"HIC"�w�w���ɤW�ѥh...\n"NOR, me, this_object() );
        me->start_busy(2);
        set("ignite",1);
        call_out("light2", 2 + random(8), me );
        return 1;
}

