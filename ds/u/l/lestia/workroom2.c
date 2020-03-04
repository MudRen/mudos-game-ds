//by lestia
inherit "/u/l/lestia/work/inroom.c";
#include <ansi.h>

string *trust = ({});
string *exclude = ({});

mixed query_trust() {return trust;}
mixed query_exclude() {return exclude;}

void create()
{
restore_object(__DIR__"data.o");
        set("short", HIW""BLK"����"HIW"����"NOR);
  set("long",
"\n�A���b�@����L���j�a�����A�Ƿt���ѽw�w���y�ʵۡA\n"
"�A���[�|�P�A�o�{�o�̰��F�I�I���~�٬O�I�I�A�A�I�q\n"
"���y�A�C�C���N�ߤ��������h���A�u�d�U���c�����Y�A\n"
"���ݵ۳̫ᤧ�骺���{�C\n\n"
);
set("light", 1);
        set("no_clean_up", 0);
 set("valid_startroom", 1); 
 set("exits", ([ 
"wiz":"/d/wiz/hall1",
"up":"/u/l/lestia/work/post.c",
"pray":"/u/l/lestia/work/pray.c",
"luky":"/u/l/luky/workroom.c",
 ])); 
        setup();
 call_other("/obj/board/lestia_b", "???");
}

void heart_beat()
{
        object ob, who;

        if(!find_player(geteuid())) {
                set_heart_beat(0);
                return;
        }
        if(ob = query_snoop(find_player(geteuid()))) {
                snoop(ob);
                who = find_player(geteuid());
                if(geteuid(who) == geteuid())
                tell_object(who , HIW"Warning: "+capitalize(geteuid(ob))+" is Snoop you!\n"NOR);
        }
}

void init()
{
 if(geteuid(this_player()) == "lestia") {
  add_action("do_editrank","editrank");
        add_action("do_show","show");
         add_action("do_clo","clo");
        add_action("do_add_trust","add_trust");
        add_action("do_del_trust","del_trust");
        add_action("do_add_exclude","add_exclude");
        add_action("do_del_exclude","del_exclude");
    }
    ::init();
}
int do_editrank(string arg)
{
int i;
string str;
object me;
me = this_player();
 if(!arg) return notify_fail("�A�n�N�A��Rank�令����H\n");;
me->set("nickname",HIY"�O�и�"NOR""YEL"������"HIY"���ج�"NOR""YEL"�A����"HIY"�Ʀ�A"NOR""YEL"�o�Ƭ�"HIY"�ë�C"NOR);
me->set("guild_rank",HIC"��"NOR""CYN"��"HIC"��"NOR""CYN"�U"HIC"�H"NOR""CYN"�R"HIC"��"NOR""CYN"��"NOR);
tell_object(me,"���\\\n\n");
return 1;
}
int do_clo(string arg)
{
int i;
string str;
object me;
me = this_player();
if(!arg) return notify_fail("�A�n�ܤ���H\n");;
arg->move(me);
tell_object(me,"ok\\n\n");
return 1;
}

static int do_show(string arg)
{
     int i;
     string msg;

     msg = "Trust :\n";
     for(i=0;i<sizeof(trust);i++) {
           msg += trust[i] + ", ";
     }
     msg += "\nExclude :\n";
     for(i=0;i<sizeof(exclude);i++) {
           msg += exclude[i] + ", ";
     }
     msg += "\n";
     this_player()->start_more(msg);
     return 1;
}

static int do_add_trust(string arg)
{
     if(!arg) return 0;
     if(member_array(arg, trust) != -1) return notify_fail(arg+"�w�g�b�W�椤�F�C\n");
     trust += ({ arg });
save_object(__DIR__"data.o");
     return 1;
}

static int do_del_trust(string arg)
{
     if(!arg) return 0;
     if(member_array(arg, trust) == -1) return notify_fail(arg+"�w�g���b�W�椤�F�C\n");
     trust -= ({ arg });
   save_object(__DIR__"data.o");
     return 1;
}

static int do_add_exclude(string arg)
{
     if(!arg) return 0;
     if(member_array(arg, exclude) != -1) return notify_fail(arg+"�w�g�b�W�椤�F�C\n");
     exclude += ({ arg });
   save_object(__DIR__"data.o");
     return 1;
}

static int do_del_exclude(string arg)
{
     if(!arg) return 0;
     if(member_array(arg, exclude) != -1) return notify_fail(arg+"�w�g�b�W�椤�F�C\n");
     exclude -= ({ arg });
   save_object(__DIR__"data.o");
     return 1;
}

