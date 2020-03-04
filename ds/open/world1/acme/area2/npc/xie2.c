/* write by -Acme-
   update by -Acme-
*/

#include <ansi2.h>
inherit NPC;

string *way = ({ // �a��
                 "south", "east", "north", "west", "west", "north", "southwest", "north",
                 "west", "south", "south", "south", "west", "west", "northeast", "northup",
                 "north", "southwest", "north", "west", "south", "west", "south", "south",
                 "south", "eastup", "east", "southwest", "east", "south", "east", "east",
                 "east", "southeast", "southeast", "westup", "northwest", "west", "south",
                 "west", "north", "west", "west", "south", "west", "up",
                 // �I�a
                 "north", "west", "west", "south", "south", "out",
                 // �ѫ�
                 "west", "west", "west","west", "west", "west", "west", "southwest", "west",
                 "west", "southwest", "westdown",
                 // �B�F��
                 "southeast", "south", "south", "west", "south", "southwest", "south",
                 "south", "southwest", "southwest",
                 // ���a��
                 "south", "east", "east", "south", "south", "east", "southeast", "eastup",
                 // �����s
                 "southeast", "southeast", "southeast", "southeast", "east", "southup", "east",
                 "eastup", "east", "northup", "west", "north",
                 // �ⶳ�x
                 "northeast", "north", "north", "west", "east", "south", "south", "southwest",
                 "northwest", "north", 
                 // �ⶳ�p
                 "north", "north", "northeast", "north", "east", "east", "east", 
                 // �ʾ]�s
                 "east", "east", "east", "south", "south", "south", "down", "east", "down",
                 
              });

void go_open_war();
void open_war();
void create()
{
    set_name( "�Ѵݨ���", ({ "tan chan xie","tan","chan","xie", "__GUARD__" }) );
    set("level",65);
    set("combat_exp",5500);
    set("evil",99);
    set("long", @Long
�L�O�խߦa�������j�ѡA�L�j�Y�ѯ��A���i�@�@�A�L�P�����H�h
�������A�q����A�g�L�L�ƪ��j�p�Ԫ��A�ԵL���J�A�L�w����
�Z�L�����Q�D�A�����H�h��L���ᬰ�Ҽ��A�\�h�ۦ��@�檺�x��
�H�A�v��۪��{�A�ӳ�ӫխߦa���A�o���o�Ͱ��L�s�C
Long);
    set("age",100);
    set("gender","�k��");
    set("title",HIR"�i�խߴc���j"NOR);
    set("Merits/wit",0);
    set("int",40);
    set_skill("sword",110);
    set_skill("dodge",110);
    set_skill("parry",110);
    set("talk_reply","�����F�A�u�n�A���h�ʧڪ����_�N��F�I�ڥͥ��̫�H�ðʧڪ��_���F�C\n");
    set("inquiry/���_", "��I�ڪ����_�i�h�F�A���I�ڤ�W�o���ѥi�O�ڦ����_�����̳߷R�F�C\n");
    set("inquiry/�_��", "��I�ڪ����_�i�h�F�A���I�ڤ�W�o���ѥi�O�ڦ����_�����̳߷R�F�C\n");
    set("inquiry/��", "�o���ѥi�O���������B���A�W�Y�g���i�աj�r�i���O�j�j�����K�C\n");
    set("inquiry/��", "�ڬݧA�o�p�٤l�Z�������A�ڴN��A���a�I\n"
                      "              �A�i�H�b�԰����ۤߪ��q��۫�(you)�A�i\n"
                      "              �H�o�X��H���¤O�@�I�I\n",
    );
    set("chat_chance_combat",80);
    set("chat_msg_combat", ({
        (:command("you"):),
        (:command("say �A�o�c��A���ڳo�@�ۡA�����a�I�I�I"):),
    }) );

    setup();
    set_living_name("__XIE__");
    carry_object(__DIR__"wp/darksword.c")->wield();
    carry_object(__DIR__"obj/book.c");
    carry_object(__DIR__"obj/bone.c");
}
void init()
{
    object demon;
    ::init();
    add_action("do_guard", "go");
    if( "/u/a/acme/god"->query_tune_game("�s�]�ûR") ) return;
    if( !this_object()->query("open_war_ok") && objectp(demon = present("_TIAN_DEMON_", environment(this_object()))) ) {
        message_vision("$N�J��$n�H�Y�����j���D�G�ѧ��z�вש�X�s�ӡA�ӧa�I�@�_�d�o��½�a�Чa�I�I\n", this_object(), demon);
        command("wahaha");
        message_vision(HIW"\n$N�N�⤤���U�~�\\���˦b$n���Y�W...\n\n"NOR, this_object(), demon);
        this_object()->set("open_war_ok", 1);   //�K�oinit() �@������
        call_out("open_war", 3);
        return;
    }
}

int do_guard(string arg)
{
    object me;
    object obj;
    me=this_player();
    obj=this_object();
    if( (arg!= "southwest") || !this_player()->visible(this_object()) ) return 0;
    write( name() + "�N�A�d�F�U�ӡC\n");
    command("say �x�I�H�p��I�I�Q���ڪ����_�ӵۡI�H");
    command("say �A�֨��a�I�U���O���ڨ���A�A�_�h�I���I�I�I");
    obj->kill_ob(me);
    return 1;
}

void die()
{
    object ob;

    if( !ob = query_temp("last_damage_from") ) ob = this_player(1);

    if( !ob ) {
        ::die();  return;
    }

    message("world:world1:vision",CYN"\n  �Z�L�ǥX�F�@�h��H������:\n\n\t�u�խߴc���v�Ѵݨ��вש�ѵ��F"+ob->name(1)+"�C\n\n"+NOR,users());
    ob->add("popularity",3); //�n��
    ::die();
    return;
}

void go_open_war()
{
    int i, way_point;
    string msg = "";
    object move_to;

    set_temp("war_opening", 1);
    way_point = this_object()->query("way_point");

    /* �p�G�b�԰��A�԰������A��� */
    if( this_object()->is_fighting() ) {
        call_out( "go_open_war", 30);
        return;
    }

    if( !way_point ) CHANNEL_D->do_channel(this_object(), "sys", "�o�X�F��ʡA�ǳƸѰ��u�ѧ��v���L�O�I\n");

    /* ���쨭�B�����Ҥ����ɡAdestruct */
    if( !environment(this_object()) ) {
        CHANNEL_D->do_channel(this_object(), "sys", "���B��������...destructing..." );
        destruct(this_object());
        return;
    }

    if( !this_object()->query("move_to") )
        this_object()->set("move_to", environment(this_object())->query("exits/"+ way[way_point]) );

    /* ���üơA�p���~���|�w�I����A�H���Q��� */
    for(i=0;i<=random(4)+3;i++) {

        if( way_point >= sizeof(way) ) break;

        switch( random(10) ) {
            case 1: command("hmm"); break;
            case 2: command("stare"); break;
            case 3: command("say �{�}�I�{�}�I"); break;
            case 4: command("emote �@�}��A�𪺻�����...\n"); break;
            case 5: command("snort"); break;
        }

        command("go " + way[way_point] );

        /* �p�G�� go �|�Q�צ��A�����N�� move */
        if( this_object()->query("move_to") != file_name(environment(this_object())) ) {

            msg += "��ϲ��椧�N...";
            message_vision("�A�ݨ�$N���κ����ҽk�A��" + to_chinese(way[way_point]) +"�����F...\n", this_object());
            if( !objectp( move_to = find_object(this_object()->query("move_to"))) || !this_object()->move(move_to) ) {
                CHANNEL_D->do_channel(this_object(), "sys", "���椧�N����...��ʨ���..." );
                return;
            } else msg += "���\\...";
        }

        if( way_point + 1 < sizeof(way) )
            this_object()->set("move_to", environment(this_object())->query("exits/"+ way[way_point+1]) );

        msg += "go " + way[way_point] + " �A����F" + environment(this_object())->query("short") + "...\n";

        /* �C�C�������B */
        if( file_name(environment(this_object())) == "/open/world1/acme/bonze/b17" ) {
            object staff;
            staff = new("/open/world1/acme/bonze/npc/wp/seven-staff.c");
            staff->move(this_object());
            command("emote �F½���@�A�o�{�F�@�Ǻݭ�...\n");
            message_vision("$N�������F������A�ΤO�a��L���ӡA���G�o�{�F����H�I\n", this_object());
        }

        /* �H���D�[-�I�� */
        if( file_name(environment(this_object())) == "/open/world1/tmr/freezetaoism/temple7" ) {
            this_object()->set("move_to", "/open/world1/tmr/freezetaoism/downroad1");
            command("emote �F½���@�A�o�{�F�@�Ǻݭ�...\n");
            command("move �Z��");
        }

        /* �a�U�۫� */
        if( file_name(environment(this_object())) == "/open/world1/tmr/freezetaoism/downroad3" ) {
            command("emote �F½���@�A�o�{�F�@�Ǻݭ�...\n");
            command("push �۾�");
        }

        /* �a�U���� */
        if( file_name(environment(this_object())) == "/open/world1/tmr/freezetaoism/downroad4" ) {
                command("hmm");
                command("insert staff into ����");
                command("hehe");
        }

//        CHANNEL_D->do_channel(this_object(), "sys", msg );

        this_object()->add("way_point", 1);
        way_point++;
    }

    if( this_object()->query("way_point") < sizeof(way) )
        call_out("go_open_war", 3);

    return;
}

void open_war()
{
    object demon;
    string msg;

    "/u/a/acme/god"->tune_game("�s�]�ûR");

    msg = "\n\t\t"HIW"�i"HIG"�ѼƲ��H"HIW"�j"NOR"�����ܦ�A�ަ��ܽG�A�ѷn�a�ʡA�s�]�R�ʡI�I�I\n\n";
    message("world:world1:vision", msg ,users());
    return;
}