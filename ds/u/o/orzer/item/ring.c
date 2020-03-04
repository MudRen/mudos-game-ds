
#include <ansi.h>
#include <armor.h>
#define CLUB_NAME "�Ѧa�|"
#define CLUB_ID "sky"
#define CLUB_CHANNEL "sky"
#define CLUB_MARK "ring of heaven and earth"
inherit FINGER;
private string *members_level = ({
        "�ګ�", //0
        "����", //1
        "���", //2
        "�@�k", //3
        "��D", // 4 by alickyuen@ds
        "����", // 5 by alickyuen@ds 
        "��D", //4->6 by alickyuen@ds
        "�`��D", //5->7 by alickyuen@ds
});
void create()
{
        set_name(HIG"�Ѧa����"NOR,({"ring of heaven and earth","ring","club_mark"}));
        set_weight(600);
        if( clonep() ) set_default_object(__FILE__);
        else
        {
                set("material","steel");
                set("club_id",CLUB_ID);
                set("club",CLUB_NAME);
                set("sub_club",({"���\\��","�a�b��","������","�k�۰�","�Z�K��"}));
                set("no_drop",1);
                set("no_sell",1);
                set("no_sac",1);
                set("unit","�u");
                set("long",@LONG
        
�������D�O�ѤU�W�K���ѤU�|�����A�H�ѤU�|�������_
(�Ѧa����)���~�βհ������A�����z�g�X�Ѻ�⪺���A
�A�O�A�ٹĸӦW�K�Ҫ᪺�ߦ�C

[����Ѧa�|����L�����Х�<help sky>���O�d�ߡC]
LONG
                );
        }
        set("value",0);
        set("club_max_level",sizeof(members_level)-1);
        set("armor_prop/shield", 1);
        set("wear_msg", HIG"$N���W�F�Ѧa�|�������_��"+name()+HIG"���P�ɡA�����q���M�t�A�ǥX�@�D����A�N���t����ǤJ$N���餺�I\n"NOR);
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
        output="\n�ثe"+CLUB_NAME+"�n�O���ת�������:\n";
        if(arg=="long")
        {
                for(i=this_object()->query("club_max_level");i>0;i--)
                {
                        for(j=0;j<sizeof(members);j++)
                        {
                                if(club[members[j]]["level"]==i) output=sprintf("%s %12s ���|����: %d\n",output,members[j],i);
                        }
                }
                output=sprintf("%s \n�ثe%s�@�p��: %d �W�����C\n",output,CLUB_NAME,sizeof(members));
                write(output);
                return 1;
        }
        temp=CLUB_D->query_club_leader(CLUB_ID);
        output=sprintf("%s ��ɤH: %12s\n",output,temp);
        list-=({temp});
        output=sprintf("%s ��L:\n",output,temp);
        output+=CLUB_D->show_club_members(CLUB_ID);
        output=sprintf("%s�ثe%s�@�p��: %d �W�����C\n",output,CLUB_NAME,sizeof(members));
        output+="\n [��listmember long �i�H�ݨ�󧹾㪺��ơC]\n";
        write(output);
        return 1;
}

