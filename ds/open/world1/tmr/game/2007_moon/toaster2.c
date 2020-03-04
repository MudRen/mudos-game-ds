#include <ansi.h>
inherit ITEM;

void create()
{
    set_name( HIG "�N�c" NOR, ({ "mooncake toaster","toaster" }) );
    set_weight(600);

        set("long",@LONG
�o�O�@�ӥΨӰ��J���p���N�c�A�A�ݭn���o���J���p���T�إ��n���ơG�_�p�֡B
�Ǫd�B���ж��J�A�H�@�w����ҩ�i�N�c���M�N�A�N�঳���|���X�����n�Y���J
���p�C�o�ӯN�c�����@���]�k�K�O�A�A�i�H�b�W����e(carve)�@�Ǧr�ˡA�o�Ǧr
�˱N�|�L�b�J���p�W�A�֦����_���]�O�C
                        
        1. carve exp 
        2. carve pop  
        3. carve art 
        4. carve money

        �S�O���G�C�@�ӯN�c���� (�гJ���Ӽ�)/4000 �����v��o�@�ӳJ���p�����C

��A��n�J���p�����Ƥ���A�u�n�Ұ�(switchon)�N�c�A�@�ߵ��J�M�N�����G�C
�A�i�H�ϥΡuinspect�v���O���˵��N�c���w�g��F�h�֧��ơC
LONG
);
    set_max_capacity(2000);
    set_max_encumbrance(2000);      // ���]�@�i�ȥu���@�J
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("value", 99);
    }
    setup();
}

void init()
{
    add_action("do_wish","carve");
    add_action("do_light","switchon");
    add_action("do_oil","inspect");
}

int moon_yolk = 0;      // �гJ��
int moon_crust = 0;     // �_�p��
int moon_puree = 0;     // �Ǫd

void countWeight() {
        int i;
        object* inv;
        
        moon_yolk = 0;
        moon_crust = 0;
        moon_puree = 0;
        
    inv = all_inventory(this_object());
    if( !sizeof(inv) )
        return;

    for(i=0; i<sizeof(inv); i++)
    {
        if( inv[i]->id("_MOON_YOLK_") )
                moon_yolk += inv[i]->query("time");
        else if( inv[i]->id("_MOON_CRUST_") )
                moon_crust += inv[i]->query("time");
        else if( inv[i]->id("_MOON_PUREE_") )
                moon_puree += inv[i]->query("time");
    }   
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
        countWeight();
    return notify_fail( sprintf("�ثe�N�c����%3d�Ӧ@%4d�J���_�p�֡B%3d�Φ@%4d���J���Ǫd�B%3d���@%4d���J���гJ���C\n",
                                getSize("_MOON_CRUST_"), moon_crust,
                                getSize("_MOON_PUREE_"), moon_puree,
                                getSize("_MOON_YOLK_"), moon_yolk
                               ));
}

int do_wish(string arg)
{
    object me;
    string wish;
    me = this_player();
    if(!arg )
        return notify_fail("�A�Q�n��e����r�ˡH\n");
    if( query("wish_type") )
        return notify_fail("�A�o�N�c�w�g��e�L�r�ˤF�C\n");

    switch(arg) {
    case "exp":
        wish = "�g���";
        break;
    case "pop":
        wish = "�n��";
        break;
    case "art":
        wish = "�԰����N";
        break;
    case "money":
        wish = "�]�I";
        break;
    default:
        return notify_fail("�A�L�k��e�o�ئr�ˡC");
    }
    message_vision( CYN"$N�Ӥߦb�N�c�W��e�u" + wish + "�v���r�ˡC\n" NOR,me);
    set("name", HIG "�N�c [" + wish + "]" NOR);
    set("wish",wish);
    set("wish_type", arg);
    //set("wish_amount",amount);
    return 1;
}

int isSuccess() {
        return random(100) < 90;
}

int isBurst() {
        // �Ǫd�O�J����3���B�֭n�O�J����2��
        return moon_puree < moon_yolk 
                        || moon_crust < moon_yolk
                        ;
                //      || random(100) < 10;    // �H���z��
}

// �Ѩt�Ψӭp��ƶq
int getAmount() {
        int am, ct, ee;
        int yolk = moon_yolk * 100 ;

        // �ΰ_�p�ֻP�Ǫd����ҡA�ӭp������̤p��
    ct = getSize("_MOON_CRUST_");
    ee = getSize("_MOON_PUREE_");
    
    switch(query("wish_type") ) {
        case "money":   // �̮e�����\
                am = yolk/13;
                break;
    case "exp":
                am = yolk/123;  
                break;
    case "pop":
                am = yolk/541;
                break;
    case "art":
                am = yolk/765;
                break;
    }
    
        return am;
}

void light2(object me) {
    string msg;
    string str;
    object cake;
    // �z�����i���
    if( isBurst() ) {
        msg = sprintf(
                  HIM "\n\n\t�u�����]�ֳt«�_�A%s�Ұʪ�"HIM"%s"HIM"�������N�ܦ�"HIR"�j���y"HIM"�A�o�ͱj�P���z���I�I�I\n\n"NOR, me->query("name"), query("name") );
        message("system",  msg, users() );
        destruct(this_object());
        return;
    }

    if( isSuccess() ) {
        cake = new("/open/world1/tmr/game/2007_moon/mooncake.c");
        cake->set("wish_type", query("wish_type") );
        cake->set("wish_amount", getAmount() );
        str =  cake->query("wish_amount") + " " + query("wish");
        cake->set("name", HIY"" + me->query("name") + "���J���p" + HIM " [" + str + "]" NOR);
        cake->move(me);

        msg = HIC"\n\t"+me->name()+HIC"��" + name() +HIC"�ǥX�}�}�����A�����n�Y��" + cake->name() + HIC"�X�l�F�I�I\n"NOR;
        
        // �S�O���Gdoll
        if( getSize("_MOON_YOLK_") > random(4000) ) {
            new("/open/world1/tmr/game/2007_moon/moon_doll.c")->move(me);
            msg += HIG"\n\t\t�@�Ӥp���i�R���J���p�����A�q�N�c���ۤF�X�Ө� "+me->name()+HIG"���⤤�C\n"NOR;
        }
        
        message("system",  msg, users() );
    } else {
        message_vision(HIM "�i��$n"HIM"���O����A���Y�����ƥb�ͤ����A�V���@����d�F�C\n"NOR, me, this_object() );
    }
    
    destruct( this_object() );
}

int do_light(string arg)
{
    object me;
    me = this_player();
    if( !arg || arg != "toaster" )
        return notify_fail("�A�Q�n�Ұʤ���H\n");
    if(me->is_busy() || me->is_fighting() )
        return notify_fail("�A�����ۡC�C\n");
    if( query("ignite") )
        return notify_fail("�o�N�c�w�g�ҰʤF�C\n");
    if( !query("wish_type") )
        return notify_fail("�o�N�c�٨S����e�r�ˡC\n");
    
    countWeight();

    message_vision(HIC"$N�Ұ�$n"HIC"���}���A�u��$n"HIC"�C�C�[���_��...\n"NOR, me, this_object() );
    me->start_busy(2);
    set("ignite",1);
    call_out("light2", 2 + random(8), me );
    return 1;
}


