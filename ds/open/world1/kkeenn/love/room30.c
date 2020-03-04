#include <ansi.h>;
inherit ROOM;
// �۵M�_�[�G����´�k
void open_star2() {
    "/adm/daemons/event/2star.c"->trigger_event();
}

void open_star() {
    call_out("open_star2",90+random(30));
}
void create()
{
        set("short", HIC"������"HIR"�T�a"NOR);
        set("long", @LONG
�@�J�T�a�A�e�豾�ۤ@�ժ��L�s��СA�W�Y�g�ۤ�j���|�Ӧr�y�C�i
���N�z�C�j�U���\�ۤ@�i�j����l�A�@��O�Ȥ�[�l�j�z�̭۫��A�@��O
�T�ئh�����C��j�ɹ��A���W�@���Q��P�g�ۡy�������W�d�ʸ��z�C�a�U
��ȤQ���i�����ȡA�W�Y�f�ۤ��m�起�۫C�ȵ��C�k�䪺��W�����Ѥ�
�����˵����D�����F�ǡA����h�O�@����O�A�W���観�����̤l���Ʀ�]
�A�i��(load)�ӬݱƦ�]�C
LONG
        );
        set("exits", ([ 
  "down"  : __DIR__"room27",
  ]));
	set("no_recall", 1);
        set("objects", ([
 __DIR__"npc/master_2" : 1,
]));
        set("light",1);
        setup();
}
void init() {
        add_action("do_billing","load");
}

int do_billing(string str) {
        object *user,me;
int i,j;

        user = users();
        me = this_player();

        for(i=j=0; i<sizeof(user); i++)
           if(user[i]->query("class1") == "������" && !wizardp(user[i]))
              user[j++] = user[i];
        if(str == "combat_exp") {
           call_out("do_exp",0,user,j);
           return 1;
        }
        else if(str == "run_cloud") {
           call_out("do_steps",0,user,j);
           return 1;
        }
        else if(str == "masen_whip") {
           call_out("do_whip",0,user,j);
           return 1;
        }
        else
           return notify_fail("�ϥή榡: load <����>\n"
                              "�g���(combat_exp)\n"+
                              "�l���y�B(run_cloud)\n"+
                              "�����@�k(masen_whip)\n\n");
}
int do_exp(object *user,int j) {
        object tmp;
        int i,k;

        for(i=0; i<(j-1); i++)
           for(k=i+1; k<j; k++) {
              if(user[k]->query("combat_exp") > user[i]->query("combat_exp")) {
                 tmp = user[i];
                 user[i] = user[k];
                 user[k] = tmp;
              }
        }

        printf(HIG"\n\t\t�������g��ȱƦ�]:\n\n"NOR);
        for(i=0; i<j; i++)
           tell_object(this_player(),
              sprintf(HIC"\t��%2d�W       %-18s %s(%s) \n"NOR,i+1,
                      user[i]->query("title"),
                      user[i]->query("name"),
                      user[i]->query("id")));
        printf("\n");
}
int do_steps(object *user,int j) {
        object tmp;
        int i,k;

        for(i=0; i<(j-1); i++)
           for(k=i+1; k<j; k++) {
              if((int)user[k]->query_skill("run_cloud") > (int)user[i]->query_skill("run_cloud")) {
                 tmp = user[i];
                 user[i] = user[k];
                 user[k] = tmp;
              }
        }

  printf(HIG"\n\t\t���������\\�Ʀ�]:\n\n"NOR);
        for(i=0; i<j; i++)
           tell_object(this_player(),
              sprintf(HIC"\t��%2d�W       %-18s %s(%s) \n"NOR,
                      i+1,
                      user[i]->query("title"),
                      user[i]->query("name"),
                      user[i]->query("id")));

        printf("\n");
}

int do_whip(object *user,int j) {
        object tmp;
        int i,k;

        for(i=0; i<(j-1); i++)
           for(k=i+1; k<j; k++) {
              if((int)user[k]->query_skill("masen_whip") > (int)user[i]->query_skill("masen_whip")) {
                 tmp = user[i];
                 user[i] = user[k];
                 user[k] = tmp;
              }
        }

        printf(HIG"\n\t\t�����������@�k�Ʀ�]:\n\n"NOR);
        for(i=0; i<j; i++)
           tell_object(this_player(),
              sprintf(HIC"\t��%2d�W       %-18s %s(%s) \n"NOR,
                      i+1,
                      user[i]->query("title"),
                      user[i]->query("name"),
                      user[i]->query("id")));
        printf("\n");
}

