#include <ansi2.h>

string WAR_DIR = "/open/world1/moonhide/westarea/";
string *god=({"lin","ean","mon","sha",
              "poo","dang","unin","liu"
             });

 string *guard=({"guard", "guard2" });

string *place=({"room2","room1","startroom","room3",
                "room4","room5","room6","room7","room8",
                "room9","room10","room11","room12","room13",
                "room14","room15","room",
                "way1", "way2", "way3", "way4", 
                "way5", "way6", "way7"
               });

int query_god()
{
    object god;

    while ( objectp(god=find_living("westwar")) )
    {
        if ( !environment(god) )
        {
            destruct(god);
            god = 0;
        }
        else break;
    }

    if ( objectp(god) ) return 1;
    return 0;
}


private void create() {
    seteuid(getuid());
}

// ��ܬO�@�ӾԪ���
int isWar() {
    return 1;
}

// �Ԫ�������ɶ�
// �p�G�]��0, ��ܾԪ�������ɶ��ۦ�]�w�A���Ѩt�α���
int getDuration() {
     return 300; // 5 min
}

// �}�l�Ԫ��ҭn���檺�ާ@
// �Ǧ^ 1 ��ܾԪ��Ұ�, 0 ��ܨS�Ұ�
int doStartWar(object me)
{
    int i;
    object g;

    message("world:world1:vision",
            HIY"\n\t"+me->query("name") +HIW "���J�E�Ѷ��ݡA�I�U���f�Ȫ��O��...\n\n"
            HIC"\t\t�i�p�� ��I���j: �M�����Z�H�I�I����ť�O�A�N�Ҧ��J�I��"HIR"�q �q �� �� �I\n\n" NOR
            ,users() );

    g = new(WAR_DIR + "obj/pill");
    g->move(WAR_DIR + place[random(sizeof(place))]);
    g = new(WAR_DIR + "obj/pill");
    g->move(WAR_DIR + place[random(sizeof(place))]);

   // soul    
    for (i=0;i< 12;i++)
    {
        g=new( WAR_DIR + "npc/"+god[random(sizeof(god))]);   // Add by -Acme-
        g->move(WAR_DIR+place[random(sizeof(place))]);   // Add by -Acme-
    }

    // guard 
    for (i=0;i< 12;i++)
    {
        g=new( WAR_DIR + "npc/"+guard[random(sizeof(guard))]);
        g->move(WAR_DIR+place[random(sizeof(place))]);
    }

     // thunder
      g = new( WAR_DIR + "npc/thunder");
     g->move(WAR_DIR+place[random(sizeof(place))]);

    
    return 1;
}
// �����Ԫ��ҭn���檺�ާ@
// �Ǧ^ 1 ��ܾԪ�����, 0 ��ܨS����
int doEndWar( )
{
    // non finish
    if ( query_god() ) return 0;

    message("world:world1:vision",
            HIY"\n\t\t\t�����㾴���㾴�����\n"NOR
            HIC"\n\t\t�E�Ѷ��ݪ����j"HIY"������"HIC"�Q�V�T�A���������n�ǹM��ӥ@�ɡI�I�I\n"NOR
        , users() );

    return 1;
}

void doHeartBeat()
{
    // nothing to check
}

