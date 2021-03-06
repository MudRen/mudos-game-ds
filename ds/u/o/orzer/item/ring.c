
#include <ansi.h>
#include <armor.h>
#define CLUB_NAME "天地會"
#define CLUB_ID "sky"
#define CLUB_CHANNEL "sky"
#define CLUB_MARK "ring of heaven and earth"
inherit FINGER;
private string *members_level = ({
        "族客", //0
        "幫眾", //1
        "堂員", //2
        "護法", //3
        "堂主", // 4 by alickyuen@ds
        "長老", // 5 by alickyuen@ds 
        "舵主", //4->6 by alickyuen@ds
        "總舵主", //5->7 by alickyuen@ds
});
void create()
{
        set_name(HIG"天地指環"NOR,({"ring of heaven and earth","ring","club_mark"}));
        set_weight(600);
        if( clonep() ) set_default_object(__FILE__);
        else
        {
                set("material","steel");
                set("club_id",CLUB_ID);
                set("club",CLUB_NAME);
                set("sub_club",({"天罡\堂","地剎堂","正雲堂","法旋堂","焯焰堂"}));
                set("no_drop",1);
                set("no_sell",1);
                set("no_sac",1);
                set("unit","只");
                set("long",@LONG
        
此指環乃是天下名匠為天下會創幫，以天下會鎮幫之寶
(天地指環)的外形組做成的，指環透射出碧綠色的光澤
，令你贊嘆該名匠所花的心血。

[關於天地會的其他說明請用<help sky>指令查詢。]
LONG
                );
        }
        set("value",0);
        set("club_max_level",sizeof(members_level)-1);
        set("armor_prop/shield", 1);
        set("wear_msg", HIG"$N戴上了天地會鎮幫之寶－"+name()+HIG"的同時，瞬間從天霖聖澤傳出一道綠光，將神聖之氣傳入$N的體內！\n"NOR);
        setup();
}

int query_autoload() { return 1; } //save_item

void init()
{
 add_action("do_listmember","listmember");
}

int do_listmember(string arg)
{
        string *list,*members,temp,output;
        int i,j;
        mapping club;
        list=CLUB_D->club_members(CLUB_ID);
        club=CLUB_D->query_club_record(CLUB_ID);
        members=keys(club);
        output="\n目前"+CLUB_NAME+"登記有案的成員有:\n";
        if(arg=="long")
        {
                for(i=this_object()->query("club_max_level");i>0;i--)
                {
                        for(j=0;j<sizeof(members);j++)
                        {
                                if(club[members[j]]["level"]==i) output=sprintf("%s %12s 幫會等級: %d\n",output,members[j],i);
                        }
                }
                output=sprintf("%s \n目前%s共計有: %d 名成員。\n",output,CLUB_NAME,sizeof(members));
                write(output);
                return 1;
        }
        temp=CLUB_D->query_club_leader(CLUB_ID);
        output=sprintf("%s 領導人: %12s\n",output,temp);
        list-=({temp});
        output=sprintf("%s 其他:\n",output,temp);
        output+=CLUB_D->show_club_members(CLUB_ID);
        output=sprintf("%s目前%s共計有: %d 名成員。\n",output,CLUB_NAME,sizeof(members));
        output+="\n [用listmember long 可以看到更完整的資料。]\n";
        write(output);
        return 1;
}

