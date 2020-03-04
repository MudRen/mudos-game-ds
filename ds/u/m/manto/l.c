#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIY"��֤ѿO"NOR, ({ "wish lamp","lamp" }) );
    set_weight(600);

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
    set_max_capacity(2000);
    set_max_encumbrance(2000);      // ���]�@�i�ȥu���@�J
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "�f");
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

int getOil() {
    object *inv;
    int i, total;
    inv = all_inventory(this_object() );
    if( !sizeof(inv) )
        return 0;

    total = 0;
    for(i=0; i<sizeof(inv); i++)
    {
        if( !inv[i]->id("_LAMP_OIL_") ) continue;
        total += inv[i]->query("time");
    }

    return total;
}

int getSize(string type) {
    object *inv;
    int i, total;
    inv = all_inventory(this_object() );
    if( !sizeof(inv) )
        return 0;

    total = 0;
    for(i=0; i<sizeof(inv); i++)
    {
        if( !inv[i]->id(type) ) continue;
        total ++;
    }

    return total;
}

int do_oil()
{
    return notify_fail( sprintf("�ثe�ѿO���� %4d�~�@ %4d���J���O�o�B%2d�~�U�U���B%2d�ӽո`����%2d��Ĳ�C�C\n",
                                getSize("_LAMP_OIL_"), getOil(), getSize("_LAMP_OIL_TOOL_"),
                                getSize("_OIL_REGULATOR_"), getSize("_OIL_CATALYST_"),
                               ));
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
        return notify_fail("�A�L�k�\\�o���@��C");
    }
    message_vision( CYN"$N�ۤ߸۷N�a��ۤѿO�\\�U�u" + wish + "�v���@��C\n" NOR,me);
    set("name", HIY"��֤ѿO [" + wish + "]" NOR);
    set("wish",wish);
    set("wish_type", type);
    set("wish_amount",amount);
    return 1;
}

// ���o�@��һݭn����O, ��쬰 1�J : 100
// 200,000 �G�Q�U -> �@�d�U
#define MAX_OIL 200000

#define MONEY_BASE 1    // �i�H��200�U
#define EXP_BASE 10             //  �i�H��20�U
#define POP_BASE 498     //  �i�H��2�U
#define ART_BASE 4987   //  �i�H��2�d

int isSuccess2() {
    int oil = getSize("_LAMP_OIL_");      // �H���J�����
    int ts = getSize("_LAMP_OIL_TOOL_"); // �H�~�����

    if( query("wish_amount") > 8000000 + random(4000000) ) return 0;

    // �@�ӧU�U����0.5%�����\�v
    if( ts > 300 ) ts = 300;
    // �ܤ֭n 500�J���o�A20%
    if( oil >= 500 && ts > random(1500) )
    {
        switch( query("wish_type") ) {
        case "exp":
            return query("wish_amount") < 12345678;
        case "pop":
            return query("wish_amount") < 123456;
        case "art":
            return query("wish_amount") < 10000;
        case "money":   // �̮e�����\
            return query("wish_amount") < 12345678;
        }
    }

    return 0;
}

int isSuccess() {
    int oil = getOil() * 100;       // �i�Ϊo��*100

    // �̤j��
    if( query("wish_amount") > 8000000 + random(4000000) ) return 0;

    switch(query("wish_type") ) {
    case "exp":
        return query("wish_amount")  <= oil/EXP_BASE && random(100) < 95;
    case "pop":
        return query("wish_amount")  <= oil/POP_BASE && random(100) < 90;
    case "art":
        return query("wish_amount")  <= oil/ART_BASE && random(100) < 80;
    case "money":   // �̮e�����\
        return query("wish_amount")  <= oil/MONEY_BASE;
    }

    return 0;
}

int isBurst() {
    int ts, cs, rs, p;
    ts = getSize("_LAMP_OIL_TOOL_"); // �H�~�����
    cs = getSize("_OIL_CATALYST_"); // �H�~�����
    // ����z��
    rs = getSize("_OIL_REGULATOR_"); // �H�~�����

    p = ts + cs - rs;
    return p > random(100);
}

void light2(object me) {
    string msg;
    int s1,s2;
    int rs, oils;
    // �z�����i���
    if( isBurst() ) {
        msg = sprintf(
                  HIM "\n\n\t�u�����]�ֳt«�_�A%s�I�U��"HIM"%s"HIM"�������N�ܦ�"HIR"�j���y"HIM"�A�o�ͱj�P���z���I�I�I\n\n"NOR, me->query("name"), query("name") );
        message("system",  msg, users() );
        destruct(this_object());
        return;
    }

    s1 = isSuccess();
    s2 = isSuccess2();      // �U�U��
    if( s1 || s2 ) {
        if( s1 )
        {
            msg = HIC"\n\t�u��"+me->name()+HIC"�� " + name() +HIC" �a�۳\\�U���@��A�ɨ�ܰ��ܰ����ѻڡC\n"NOR;
        } else  {
            msg = HIC"\n\t�u��"+me->name()+HIC"�� " + name() +HIC" �a�۳\\�U���@��A�{�p"HIR"�ۤ�"HIC"�@�ˡA�b�ѪŤ��Ƭ��@��"HIR"���y"HIC"�I�I\n"NOR;
        }

        oils = getSize("_LAMP_OIL_TOOL_");
        rs  = 0;
        if( oils >= 10 ) {
            rs = getSize("_OIL_CATALYST_"); // Ĳ�C
            if(rs>30) rs = 30;
            if( rs > 0 ) {  // ��Ĳ�C
                msg += sprintf(
                           HIY "\n\t�L�����굺�R��"HIM"�Ϥ�"HIY"�q%s"HIY"����o�X�ӡA�b�ѪŤۤƦ������������I�I\n"NOR, query("name") );

                add("wish_amount", query("wish_amount")*rs/100);
            }
        }

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

        // �S�O���Gdoll
        if( getSize("_LAMP_OIL_") > random(10000) ) {
            new("/open/world1/tmr/game/2007_light/wish_lamp_doll.c")->move(me);
            msg += HIG"\n\t\t�u���@�Ӥp���i�R���ѿO�����q�ѻڽw�w���� "+me->name()+HIG"���⤤�C\n"NOR;
        }
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
    if(me->is_busy() || me->is_fighting() )
        return notify_fail("�A�����ۡA�S�����I�ѿU�C\n");
    if( query("ignite") )
        return notify_fail("�o�ѿO�w�g�I�U�A���b�ɪŤ��C\n");
    if( !query("wish_type") )
        return notify_fail("�A�o�ѿO�٨S���\\�L�@�C\n");
    if( getOil() < 1 )
        return notify_fail("�o�ѿO���S���O�o�A�L�k�I�U�C\n");

    message_vision(HIC"$N�I�U$n"HIC"�����O�o�A�u��$n"HIC"�w�w���ɤW�ѥh...\n"NOR, me, this_object() );
    me->start_busy(2);
    set("ignite",1);
    call_out("light2", 2 + random(8), me );
    return 1;
}


