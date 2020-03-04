#include <ansi.h>
#include <path.h>

inherit ITEM;

string *animal_files = ({
  "tiger_war.c",
  "rod_war.c",
  "snake_war.c",
  "leopard_war.c",
  "wildcat_war.c",
  "boar_war.c",
  "bear_war.c",
});

string *locate = ({
  "2f2.c",
  "3f1.c",
  "3f3.c",
  "4f1.c",
  "4f2.c",
  "1f2.c",
  "1f4.c",
});

string *room = ({
  "/open/world1/cominging/purple_sun/1f5.c",    // �U�s����
//  "/open/world1/cominging/purple_sun/psin7.c",
});

void create()
{
        set_name(HBK "�j�۽L" NOR, ({ "stone dish", "dish" }));
        set("long", "�@�ӫܤj���۽L, �A�i�H�լݬݥ� lay ��F��b�W�� lay xxx on stone dish�C \n");
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("value", 0);
                set("no_sac", 1);
                set("no_get", 1);
                set("no_sell",1);
        }
        setup();
}

void open_war(object me);
void end_war();
int query_ghost();

void init()
{
        add_action("do_lay", "lay");
}

int do_lay(string arg)
{
        object me = this_player(), d_stone;
        string ob, on;

        if( !arg || sscanf(arg, "%s on %s", ob, on) != 2 )
                return notify_fail("�A�Q�n�񤰻�F��W�h�H\n");
        if( !objectp( d_stone = present( ob , me ) ) )
                return notify_fail("�A���W�S���o�ӪF��I\n");
        if( on != "stone dish" )
                return notify_fail("�A�n�N"+d_stone->name()+"��b���H\n");
if( !d_stone->id("open-war-stone") && !d_stone->id("open-war-head") )
                return notify_fail("�A��"+d_stone->name()+"��b�j�۽L�W�A���O����Ƥ]�S���o�͡C\n");
if( query_ghost() || query("war_start") )
                return notify_fail("�A��"+d_stone->name()+"��b�j�۽L�W�A���O����Ƥ]�S���o�͡C\n");

set("war_start", 1);
message_vision(HIC"$N��$n���j�۽L�C\n"NOR, me, d_stone);
me->start_busy(2);
destruct(d_stone);              // �����
call_out("open_war",3, me);
return 1;
}

void open_war(object me)
{
        int i, j;
        object g, animals;

        message("world:world1:vision",
HIM"\n\t"+me->query("name") +HIM "�Ѷ}�����s�W���c��D�~�����ʦL�A�ިӧN�ŵL�����g�~�j�x......\n\n"
HIR "\t\t�����s���W�g�~�ɰʡA���͵L�ơA�ͪ��ɬҴq���k�͡I�I\n\n" NOR
,users() );

        // �~��
         g = new( COMINGING_PAST + "purple_sun/npc/king" );
         g->move( COMINGING_PAST+"purple_sun/hole5" );
    
        // �@��ʪ�
        for(i=0;i<sizeof(animal_files);i++)
        {
for(j = 0 ; j < 2 + random(4); j++)
{
animals = new(COMINGING_PAST+"purple_sun/npc/" + animal_files[i]);
animals->move(COMINGING_PAST+"purple_sun/" + locate[random(sizeof(locate))]);
}
}
/*
for(i=0;i<sizeof(room);i++)
load_object(room[i])->fall_stone();     // �޵o���ۡA�L�k�U�s
*/

        call_out("end_war",180);
        return;
}

void end_war()
{
        object ghost;

        if( query_ghost() ) {
        call_out("end_war",30);
return;
}

set("war_start", 0);
        message("world:world1:vision",
CYN"\n\t�����s���W�g�~�ɰ��A�S�^�_���ɪ����R�F......\n\n" NOR
        ,users() );
}

int query_ghost()
{
        object ani;

        while( objectp(ani=find_living("animal-war-object")) )
        {
                if( !environment(ani) )
                {
                        destruct(ani);
                        ani = 0;
                }
                else break;
        }

        if( objectp(ani) ) return 1;
        
        return 0;
}

