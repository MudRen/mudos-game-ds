inherit ITEM;

#include <ansi.h>

void create()
{
        set_name(HIC+"�d��ip�u��"+NOR,({"ip trace tool","ip","tool"}));
        set("long",@LONG
...................................................................
LONG
        );
        set("unit","��");
        setup();

}

void init()
{
        add_action("do_trace","trace");

}

int do_trace(string arg)
{
        object ob,me,body;
        int i,j,k;
        string *dira,*dirb,name,*strs,str;

        me = this_player();
        dira = get_dir("/data/login/");
        for(i=0;i<sizeof(dira);i++) {
                dirb = get_dir("/data/login/"+dira[i]+"/");
                for(j=0;j<sizeof(dirb);j++) {
                        name = dirb[j][0..(sizeof(dirb[j])-3)];
                        if( !FINGER_D->finger_user(name) ) continue;
                        strs = explode(FINGER_D->finger_user(name),"\n");
                        for(k=0;k<sizeof(strs);k++) {
                                if(strs[k][0..strlen("�W���s�u�a�}�R")-1] == "�W���s�u�a�}�R") {
//                                      str = strs[k];                  
                                        sscanf(strs[k],"�W���s�u�a�}�R%s(%*s",str);
                                        if(str == arg) tell_object(me,name+" "+str+"\n");
                                                break;
                                }
                        }
                }
        }
  
        return 1;        
}

