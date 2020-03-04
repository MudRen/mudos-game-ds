#include <ansi.h>
#include <path.h>

inherit NPC;
inherit SELLMAN;
int sort_user(object ob1, object ob2);
void open_war(int x);
void end_war();

void create()
{
        set_name("�����W���j���G�ѤH",({"unknow oldman","oldman","man"}) );
        set("long",@LONG
�@�Ӥ�����m�W���ѥ��͡A�ݤ��X�h�j�~���A�d�ۤ@�j����G�l�A��
�y���q�q���ƬO�ũM�A���ۤj���⪺�j��A�˦��_�S�A���O�o�ɥN�����
�A�I�W�t�ۤ@�Ӥj���⪺�U�l�A�ݰ_�ӹ������A�����ˤFԣ���N�C�L�o�{
�A���ݵۥL�A�H�J��ۧA���������ۡC
LONG
);
        set("age",1200);
        set("level",1);
        set("attitude", "peaceful");
        set("race","�H��");
        set("gender", "�k��" );
        set("chat_chance",10);
        set("chat_msg",({
        (:command("sing �m�m����m�m����a�n�h�T�G���"):),
        "�ѤH���������F�_�ӡA���G�D�`�����C\n",
        "�ѤH���ۻy���D�G�u�@�~���o�U�Ӥ@���A�o�O�U�Ӯ������������s�̡C�v\n",
        (:command("say ����ɯɦ�Ҧ��H"):),
        }) );
        set("sell_list",([
                __DIR__"net" : 10       ,
        ]) );
        setup();
}


void open_war(int x)
{
        int mark_loaded;
        int i, j, w;
        string dir;
        mixed *file;
        object ob,c,p;
        ob=this_object();
//        if( ob->query("open_war")==1 ) return;
        switch (x)
        {
        case 1:         //�ɿ�
        command("scream");
        message("world:world1:vision",
HIY "\n\t���K���N ���X���� �ɯɬh���g�� �����Z��ûR\n\n" NOR
HIW "�i�t�Ϥ����j�ɿ��B�ѫ��B�B�F�����U�a���D���n�|�_�I�I\n\n"NOR
CYN "(�t�Ϥ����j�ɨ��I�I)\n" NOR
        ,users() );
               return; // By Tmr
        dir = resolve_path("/open/world1/tmr/area/", "");
        if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) dir += "/";
        file = get_dir(dir, -1);
        if( !sizeof(file) ) return;
        i = sizeof(file);
        w = 0;
        while(i--) {
                if (file[i][1]==-2) file[i][0] += "/";
                if (strlen(file[i][0])>w) w = strlen(file[i][0]) + 1;
        }
        while (i<33)
        {
                j=random(sizeof(file) );
                  if (strsrch(file[j][0], "/") < 0 && stringp(file[j][0]) ) 
                {
                i++;
                c=new(__DIR__"chicken");
                c->move(TMR_PAST+"area/"+file[j][0] );
                }
        }
        call_out("open_war",10,x+1);

        break;
        case 2:         //�ѫ�
        dir = resolve_path("/open/world1/acme/area/", "");
        if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) dir += "/";
        file = get_dir(dir, -1);
        if( !sizeof(file) ) return;
        i = sizeof(file);
        w = 0;
        while(i--) {
                if (file[i][1]==-2) file[i][0] += "/";
                if (strlen(file[i][0])>w) w = strlen(file[i][0]) + 1;
        }
        while (i<33     )
        {
                j=random(sizeof(file) );
                  if (strsrch(file[j][0], "/") < 0 && stringp(file[j][0]) ) 
                {
                i++;
                c=new(__DIR__"chicken");
                c->move(ACME_PAST+"area/"+file[j][0] );
                }
        }
        call_out("open_war",10,x+1);
        break;

        case 3:         //�B�F��
        dir = resolve_path("/open/world1/cominging/area/", "");
        if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) dir += "/";
        file = get_dir(dir, -1);
        if( !sizeof(file) ) return;
        i = sizeof(file);
        w = 0;
        while(i--) {
                if (file[i][1]==-2) file[i][0] += "/";
                if (strlen(file[i][0])>w) w = strlen(file[i][0]) + 1;
        }
        while (i<33)
        {
                j=random(sizeof(file) );
                  if (strsrch(file[j][0], "/") < 0 && stringp(file[j][0]) ) 
                {
                i++;
                c=new(__DIR__"chicken");
                c->move(COMINGING_PAST+"area/"+file[j][0] );
                }
        }
        break;
        }
        return;
}

void end_war()
{
        object chicken,ob;
        ob=this_object();

        if(ob->query("open_war")!=1) return;
        if(objectp(chicken=find_living("Merry_Xmas_chicken") ) )
        {
                if(!environment(chicken)) destruct(chicken);
                call_out("end_war",60);
        }
        else {
message("world:world1:vision",HIY "\n\n�t�ϦѤH�ּ֪��۹D�G�ڪ�����ڪ������w�g������F�C\n\n" NOR,users() );
                ob->set("open_war",0);
        }       
        return;
}

void init()
{
        ::init();
        add_action("do_change","change");
         add_action("do_list","llist");
          add_action("do_buy","bbuy");
       add_action("do_speak","speak");
      add_action("do_gamelist","gamelist");
}

int do_speak(string arg)
{
        object me,ob;
        me=this_player();
        ob=this_object();
        if(!arg || arg!="���j�a�t�ϸ`�ּ�" ) return 0;

           message_vision(HIG "$N���n���D�G�u���j�a�t�ϸ`�ּ֡I�I�v\n" NOR,me);

        if (this_object()->query("open_war")==1 )  
        {
             message_vision(HIR"$N���D�G�����٨S�����a�A�[�o�I�I�[�o�I�I\n"NOR,ob);
             call_out("end_war",1);
        }
        else {
             ob->set("open_war",1);
             call_out("open_war",1,1);
        }
        return 1;
}

int do_change(string arg)
{
        int i;
        object me,p;

        me=this_player();
        i=me->query("Merry_Xmas/chicken");

        if(!arg) return notify_fail("�A�Q�I��������~�H(exp)(pill)(popularity)\n");
        switch (arg)
        {
        case "exp":
        message_vision("$N�Q�I���g��ȡC\n",me);
        if (i<1) return notify_fail("�A�L�k�I���g��ȡC\n");
        message_vision(HIY "$N�q�I�᪺�j����U�l���X�ӡu500 exp�v�e���F$n�C\n" NOR ,this_object(),me );
        me->add("exp",500);
        me->add("Merry_Xmas/chicken",-1);       
        break;

        case "pill":
        message_vision("$N�Q�I���t���ĤY�C\n",me);
        if (i<5) return notify_fail("�A�L�k�I���t���ĤY�C\n");
        p=new(__DIR__"xmaspill");
        p->move(me);
        message_vision(HIY "$N�q�I�᪺�j����U�l���X�����İe���F$n�C\n" NOR ,this_object(),me );
        me->add("Merry_Xmas/chicken",-5);
        break;

        case "popularity":
        message_vision("$N�Q�I���n��C\n",me);
        if (i<10) return notify_fail("�A�L�k�I���n��C\n");
        message_vision(HIY "$N�q�I�᪺�j����U�l���X�@�I�n��e���F$n�C\n" NOR ,this_object(),me );
        me->add("popularity",1);
        me->add("Merry_Xmas/chicken",-10);
        break;

        default:
        return notify_fail("�S���o�ؼ��~����I���C\n");
        break;
        }
        return 1;
}

int do_gamelist()
{
        string str, *option;
        object *list,me;
        int i, j, ppl_cnt,opt_id;
        
        me=this_player();
        str = HIW "��  �t�Ϥ����j�ɨ��u�W�ƦW \n" NOR;
        str += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";
        list = users();
        list = sort_array(users(), "sort_user", this_object());
                ppl_cnt = 1;
                j = sizeof(list);
                while( j-- ) {
                        // Skip those users in login limbo.
                        if( !environment(list[j]) ) continue;
                        if(!list[j]->query("Merry_Xmas/chicken") ) continue;
                        if( me && !list[j]->visible(me) ) continue;             
          str = sprintf("%s%-30s%s",
           str,
              "��"+(string)ppl_cnt+"�W�G"+list[j]->query("name"),
              (string)list[j]->query("Merry_Xmas/chicken")+"���C\n",
           );
                        ppl_cnt++;
                }
                
        str += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";
        me->start_more(str);
        return 1;
}

int sort_user(object ob1, object ob2)
{
        int ord;

        ord = ob1->query("Merry_Xmas/chicken")-ob2->query("Merry_Xmas/chicken");
        if( ord==0 )
                ord = (int)ob1->query_level() - (int)ob2->query_level();
        return ord;
}



