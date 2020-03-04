// this is a ob wrote by saveob
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("�M���۸O",({ "stele", "ste","s"}));
        set_max_encumbrance(1000000);
        set_weight(1);
        set("lock",1);
        if(clonep())
           set_default_object(__FILE__);
        else{
        
           set("long","
�C�����~�d�M���ϥάy�{�G

1 .�M�����w��W���a�A�i�H�� <blist> ���O����ܥثe�O�_�����a�ѻP�M��
2 .�Y�L�H�b�M���A�i�ϥ� <addin> ���O�}�s�M��
3 .�ϥ� <view> �Χֳt�� <v> ���O�s���Գ�
4 .�ϥ� <view hand> �Χֳt�� <v hand> ���O�s����P�M�s��
        <view die> �d�ݼX���̦����ǥd
5 .�ϥ� <dump> �ӥX�P�A���O�榡 dump <��P�s��> (defend)
6 .�ϥ� <cpk> ���O�R�O�ۤv���԰����~���������~�Ϊ������a���H
   <cpk �ڤ�Ǫ��s�� �Ĥ�Ǫ��s��>  <pk �ڤ�ǽs�� 10>
7 .�ϥ� <magic> �i�H���X�]�k�d magic <��P�s��> <�Ǫ��s��>
8 .�ϥ� <tactic �Ǫ��s��> ���O�i�H�������W�԰����~�������u�ƪ��A
9 .�ϥ� <add> ���O�ӸɥR��X����P�A�Ĥ@�^�X����ϥΦ����O��P
   �`�N�G��P��K����A�������ʡA�u�� <over> ���U�@�쪱�a���
10.�ϥ� <over> ���O�����^�X�A���U�@�쪱�a���
11.��Aı�o�A�@�L�Ӻ��A�A�i�H�ϥ��еP <cover> ���ʧ@�ӻ{��
12.�ϥ� <history> ���O�i�H�d�ߦۭ��s�Ұʨ�{�b�����Z��
");
           set("unit","��");
           set("unit","��");
           set("value",1);
           set("no_get",1);
        }
}

void init()
{
        add_action("do_list","blist");
        add_action("do_cover","cover");
        add_action("do_addin","addin");
        add_action("do_view","view");
        add_action("do_dump","dump");
        add_action("do_magic","magic");
        add_action("do_tactic","tactic");
        add_action("do_add","add");
        add_action("do_over","over");
        add_action("do_pk","cpk");
        add_action("do_go","go");
        add_action("do_view","v");
        add_action("do_history","history");
}

int game_over(object me)
{
   object *inv;
   int i;
        message_vision("�ש�䤤�@�W���a���}�F�M����,�]���M�������F...\n",me);

        delete("1p"); delete("2p");
        delete("1p_hp"); delete("2p_hp");
        delete("1p_mhand"); delete("2p_mhand");
        delete("1p_mpk"); delete("2p_mpk");
        delete("player"); delete("earth");
        delete("round"); delete("check_round"); 
        delete("hcards");  delete("cards"); 

        inv = all_inventory();
        for(i=0;i<sizeof(inv);i++) {
           destruct(inv[i]);
        }

        message_vision(HIR"\n���W�Ҧ��԰����~���@�|���������F�C\n"NOR, this_player());

        return 1;
}

object *query_cards(string kind)
{
   object *cards;
   int i;
   object *m_cards=({}),*t_cards=({}),*p_cards=({}),*d_cards=({});
          //m_cards:�ϥΤ����]�k�d,t_cards:�ϥΤ��������d,p_cards:�Ǫ��d,d_cards:�X�����d

        cards=all_inventory();//���o�Ҧ����W�d�����(�]�t���۩Φ��h���Ǫ�,�]�k�d,�����d)
        for(i=0;i<sizeof(cards);i++){
          if(cards[i]->query("die")){ //�e�J�X�����Ǫ�
            d_cards+=({cards[i]});  continue; }
          if(cards[i]->query("attrib")){//���~�d
            p_cards+=({cards[i]});  continue; }
          if(cards[i]->query("magic")){//�]�k�d�ϥΤ�
            m_cards+=({cards[i]});  continue; }
          if(cards[i]->query("trap")){//�����d�ϥΤ�
            t_cards+=({cards[i]});  continue; }
        }
        if(kind=="magic") cards=m_cards;
        if(kind=="die") cards=d_cards;
        if(kind=="trap") cards=t_cards;
        if(kind=="pk") cards=p_cards;
        return cards;
}


int do_list(string arg)
{
   object p1,p2;

        p1=query("1p");
        p2=query("2p");
        if(!p1) return notify_fail("�ثe�M�����W�S�����a�C\n");
        else if(p1 && !p2) 
           return notify_fail("�ثe�M�����W���@�쪱�a"+HIY+p1->name()+NOR+"���b���ݹ��C\n");
        else return notify_fail("�ثe�M�����W���@�쪱�a"+HIY+p1->name()+
                NOR+"�M�t�@�쪱�a"+HIY+p2->name()+NOR+"���b���۸��l�C\n\n"+
                HIY+p1->name()+NOR+"���P�ո��٦�"+HIR+chinese_number(sizeof(query("cards/1p")))
                +NOR+"�i�P�A��"+HIY+p2->name()+NOR+"���P�ո��٦�"+HIR+
                chinese_number(sizeof(query("cards/2p")))+NOR+"�i�P\n");
        return 1;
}

int do_addin(string arg)
{
   object env,me,p1,p2,book_1,book_2;
   string *earth_name = ({ "�","���","�h�A","�s��","�˪L","�F�z","�X��","�}��","���v" });
   string earth = earth_name[random(sizeof(earth_name))];
   int i;
   mapping datas,cards=(["1p":([]),"2p":([])]);
   string *card;

        me = this_player();
        env=environment(this_object());

        p1=query("1p");
        p2=query("2p");
        if(!present("card book",me)) return notify_fail("�A���h�ˤ@�M�P�զA�ӨM���a�I\n");
        if(!p1){
           set("1p",me);
           set(me->query("id"),"1p");
           message_vision(HIY"\n$N"HIY"���W�M���x�A�j�ۡG���S���H�����"+me->name()+"�Ӥ@�L�M���ڡI\n"NOR, me);
        } else if(p1 && !p2) {
           if(me == p1) return notify_fail("�A�w�g�ѻP�M���F�r�I\n");
           set("2p",me);
           set(me->query("id"),"2p");
           message_vision(HIY"\n$N"HIY"���W�M���x�A�s�۹D�G"+p1->name()+"�I��"+me->name()+"�Ӹ�A���I\n"NOR,me);
           p1 = present(query("1p"),env);
           p2 = present(query("2p"),env);
           if(!p1 || !p2) return notify_fail("���@��M���̤����]���̥h�F...=.=\n");
           message_vision(HIG"\n$N"HIG"���D�G"NOR"�M���I\n", p1);
           message_vision(HIG"\n$N"HIG"���D�G"NOR"�M���I\n", p2);
           tell_object(p1,HIC"\n�A�N�A���P�թ�m�b�����W�A�q�������N�A���P�ո�ưO���U�ӡC\n"NOR);
           tell_object(p2,HIC"\n�A�N�A���P�թ�m�b�����W�A�q�������N�A���P�ո�ưO���U�ӡC\n"NOR);

           book_1=present("card book",p1);//���o�԰��P�ո��
           book_2=present("card book",p2);

           datas=book_1->query_fcards();//�N�԰��P�ո�ưO�J������
           card=keys(datas);
           for(i=0; i<sizeof(card); i++) {
             cards["1p"][card[i]]=1;
           }
//         set("1p_num",sizeof(card));
           datas=book_2->query_fcards();//�N�԰��P�ո�ưO�J������
           card=keys(datas);
           for(i=0; i<sizeof(card); i++) {
             cards["2p"][card[i]]=1;
           }
           set("cards",cards);
           set("hcards",(["1p":([]),"2p":([])]));

           if(random(2) == 1) {
                message_vision(HIW"\n�����M���� "+HIG+"$N"+HIW" �}�l��P"NOR,p1);
                tell_object(p1,"(add)");
                set("player",p1);
           } else {
                message_vision(HIW"\n�����M���� "+HIG+"$N"+HIW" �}�l��P"NOR,p2);
                tell_object(p2,"(add)");
                set("player",p2);
           }
           set("earth",earth);
           message_vision(HIW"�A�ӨM�������a���H����˪� �u"+earth+"�v�I�I\n"NOR,me);
           set("1p_mhand",5);//�̤j��P�ƶq
           set("2p_mhand",5);
           set("1p_mpk",5);//�̤j���W���~�ƶq
           set("2p_mpk",5);
           set("die_cards",([]));
           set("magic",({}));
           set("1p_hp",8000);
           set("2p_hp",8000);
//         set("check_round",1);
        } else {
           if(me == query("1p") || me == query("2p"))
                return notify_fail("�A�w�g���B�M���x�W�F�C\n");
           write("�ثe�w����쪱�a�b�ϥΨM�����C");
           message_vision(HIR"\n$N"HIR"�����ڳڪ��۹D�G�ڤ]�n���ա��\n"NOR,me);
        }
        return 1;
}




string list_hcard(object ob)
{
   mapping data;
   string *card;
   string str="",who;
   int i;

        who=query(ob->query("id"));
        data=query("hcards/"+who);
        if(sizeof(data)<1) return "";
        card=keys(data);
        for(i=0;i<sizeof(card);i++){
          str+="\t"+"("+i+") "+card[i]->name()+"\n\t\t\t";
          if(card[i]->query("attrib"))
            str+=card[i]->query("attrib")+HIR" �����O�F"+card[i]->query("ap")+NOR
               +"�A"+HIB"�u�ƤO�F"+card[i]->query("dp")+NOR""+
               (card[i]->query("doc")?("\n\t\t\t"+card[i]->query("doc")):"")+"\n";
          else str+=card[i]->query("doc")+"\n";
        }
        return str;
}

string list_card(object card,string p,string owner,int i)
{
//�d������� �ǤJ:�d������ && ��r("1p"��"2p")

   string str="";

//      if(card->query("magic")) return "";
        if(card->query("owner")==owner){
           if(card->query("owner")==p){
             str+="("+i+")";
             str+=card->query("defend")?HIG"<�u>":"    ";//���u
             str+=card->query("attrib")+card->short();
             str+="\t"HIR"�����O�G"+card->query("ap")+HIB"\t�u�ƤO�G"+card->query("dp")+NOR;
             str+=card->query("hide")?HIM"(�л\\��)"NOR:"";
             str+="\n";
           }else return "";
        }else{
           if(card->query("owner")==p){
             str+="("+i+")";
             str+=(card->query("defend")?HIG"<�u>":"    ");//���u
             if(card->query("hide"))
                str+=BLK"[�H]"NOR+"�л\\���u�Ʃ��~�d(Unknow card)\n";
             else{
               str+=card->query("attrib")+card->short();
               str+="\t"HIR"�����O�G"+card->query("ap")+HIB"\t�u�ƤO�G"+card->query("dp")+NOR;
               str+="\n";
             }
           }else return "";
        }
        return str;
}

int get_amount(string user,object *cards)//���o�԰����W���Ǫ��ƶq;user="1p" or "2p"
{
   int i,count=0;

        for(i;i<sizeof(cards);i++){
           if(cards[i]->query("owner")!=user) continue;
//         if(cards[i]->query("magic")) continue;//���b�ϥ��]�k��
           count++;
        }
        return count;
}

int do_view(string arg)
{
   object env,me,a,b,*cards;
   int i;
   string str="",str2="",round,p;

        me = this_player();
        env = environment(me);

        if(!query("1p") || !query("2p")) return notify_fail("�ثe�M���x�W�S���M���C\n");

        a = present(query("1p"),env);
        b = present(query("2p"),env);

//      if(me!=a && me!=b) return 0;

        if(!a||!b) return game_over(me);

        if(arg=="hand") {
           write("�A�⤤���d���G\n");
           write(list_hcard(me));
           return 1;
        }
        if(arg=="die"){
           write("�b�X�����d���G\n");
           cards=query_cards("die");
           if(sizeof(cards)<1) return 1;
           for(i=0;i<sizeof(cards);i++){
             write("\t("+i+") "+cards[i]->name()+"\n");
           }
           return 1;
        }

        p=query(me->query("id"));
//      cards = all_inventory();
        cards=query_cards("pk");
        if(sizeof(cards)>0){//���a�Ҭݨ쪺���p
           for(i=0;i<sizeof(cards);i++){
//           str+="("+i+")"+list_card(cards[i],query(a->query("id")),p);
//           str2+="("+i+")"+list_card(cards[i],query(b->query("id")),p);
             str+=list_card(cards[i],query(a->query("id")),p,i);
             str2+=list_card(cards[i],query(b->query("id")),p,i);
           }
        }

        if(me!=a && me!=b){
          str="";
          str2="";
          if(sizeof(cards)>0){//���[�̩Ҭݨ쪺���p
             for(i=0;i<sizeof(cards);i++){
               str+=list_card(cards[i],query(a->query("id")),"3p",i);
               str2+=list_card(cards[i],query(b->query("id")),"3p",i);
             }
          }
        }

        write(str);
        write("���������������������������������������������������������������������������� \n");
        if(strlen( a->query("id") ) < 8)
                write("���@�@�@�M���̡G"+a->query("id")+"\t\t�ͩR�ȡG"HIB+query("1p_hp")+NOR" ��");
        else
                write("���@�@�@�M���̡G"+a->query("id")+"\t�ͩR�ȡG"HIB+query("1p_hp")+NOR" ��");

        if(query("player") == a)
                write("�@�@"HIR"�� ����"NOR"�@�@"BLU"�� ����"NOR"     ��\n");
        else
                write("�@�@"RED"�� ����"NOR"�@�@"HIC"�� ����"NOR"     ��\n");

        if(!query("round")) round = " "HIC"�����P"NOR" ";
        else if(strlen(chinese_number(query("round"))) == 2)
                round = "�@�@"+HIM+chinese_number(query("round"))+NOR+"�@�@";
        else if(strlen(chinese_number(query("round"))) == 4)
                round = "�@ "+HIM+chinese_number(query("round"))+NOR+" �@";
        else if(strlen(chinese_number(query("round"))) == 6)
                round = "�@"+HIM+chinese_number(query("round"))+NOR+"�@";
        else if(strlen(chinese_number(query("round"))) == 8)
                round = " "+HIM+chinese_number(query("round"))+NOR+" ";
        else if(strlen(chinese_number(query("round"))) == 10)
                round = ""+HIM+chinese_number(query("round"))+NOR+"";

write("���������������������������������������������������������������������������� \n");
write("���@�@"HIY"�����]�k�����d"NOR"�@�@���@�@�@�@�@�@�@�@�@�@�@�@���@�@�@�@�@�@�@�@�@�@�@��
��������������������������c�c�c�c�c�c�c�c�c�c�c�c��������������������������
���@�@�@�@�@�@�@�@�@�@�@�������@�@�@�@�@�@�@�@�������@�@�@�@�@�@�@�@�@�@�@��
�������������������������⡽�@�@�@�@�@�@�@�@�@�@����������������������������
���@�@�@�@�@�@�@�@�@�@�@�����@�@ ���a�G"+query("earth")+" �@�@�����@�@�@�@�@�@�@�@�@�@�@��
�������������������������⡽�@�@�@�@�@�@�@�@�@�@����������������������������
���@�@�@�@�@�@�@�@�@�@�@�����@�^�X�G"+round+"�@�����@�@�@�@�@�@�@�@�@�@�@��
�������������������������⡽�@�@�@�@�@�@�@�@�@�@����������������������������
���@�@�@�@�@�@�@�@�@�@�@�������c�c�c�c�c�c�c�c�������@�@�@�@�@�@�@�@�@�@�@��
��������������������������@�@�@�@�@�@�@�@�@�@�@�@��������������������������
���@�@�@�@�@�@�@�@�@�@�@���@�@�@�@�@�@�@�@�@�@�@�@���@�@"HIW"�����]�k�����d"NOR"�@�@��
");

        write("���������������������������������������������������������������������������� \n");
        if(strlen( b->query("id") ) < 8)
                write("���@�@�@�M���̡G"+b->query("id")+"\t\t�ͩR�ȡG"HIB+query("2p_hp")+NOR" ��");
        else
                write("���@�@�@�M���̡G"+b->query("id")+"\t�ͩR�ȡG"HIB+query("2p_hp")+NOR" ��");

        if(query("player") == b)
                write("�@�@"HIR"�� ����"NOR"�@�@"BLU"�� ����"NOR"     ��\n");
        else
                write("�@�@"RED"�� ����"NOR"�@�@"HIC"�� ����"NOR"     ��\n");

        write("����������������������������������������������������������������������������\n");
        str = "";
        write(str2);
        return 1;
}

int do_over(object me)
{
   string *saying_name = ({ "�ڳo�@�^�X�w�g�����F�I","���A�X�P�I�񰨹L�ӧa�I",
                            "�ڳo�^�X�P�X���F�I���A�I","�ڳo�^�X�즹����A�ӧA�I" });
   string saying = saying_name[random(sizeof(saying_name))];
   string p;
   object next;
   object *magic;
   int i;
   object *cards;

        if(!me) me=this_player();
//      write(query("player")->name());
        if(me != query("player")) return notify_fail("�{�b���O����A���ܡC\n");

        message_vision(HIW"\n$N"HIW"�j�ۡG"+NOR+saying+"\n", me);

        p=query(me->query("id"));
        if(p=="1p") next=query("2p");
        else next=query("1p");
        tell_object(next,HIG"����A���^�X�}�l�F�C\n"NOR);
        set("player",next);

        if(query("check_round")>0){
          set("check_round",0);
          add("round",1);
        }else add("check_round",1);
        delete("dump");
// ***************************** �d���S��\��(start) *****************************
        if(magic=query("magic")){//�@�q�]�k
            for(i=0;i<sizeof(magic);i++){
//            magic[i]->check_magic(this_object(),me,"over",0);//�A���Ұ��]�k
              if(!objectp(magic[i])) continue;
              if(magic[i]->check_magic(this_object(),me,0,0,"over")) return 1;//�A���Ұ��]�k
            }
        }
// ***************************** �d���S��\��(end) *****************************   
        cards=query_cards("pk");
        if(sizeof(cards)>0){
           for(i=0;i<sizeof(cards);i++){
                cards[i]->delete("act");
           }
        }

        return 1;
}

int do_add(string arg)//��P
{
   object me,a,b,player;
   int i,hnum,cnum,n,max_hand;
   string p;
   mapping data=([]),hcards=([]);
   string *card;

        me = this_player();

        a=query("1p");
        b=query("2p");

        if(me!=a && me!=b) return 0;

        player=query("player");
        if(player!=me) return notify_fail("�{�b���O����A���ܡC\n");;
        p=query(me->query("id"));

        data=query("cards/"+p);//���o�P�ո��
        hcards=query("hcards/"+p);//���o��P���
        hnum=sizeof(hcards);
        cnum=sizeof(data);
        max_hand=query(p+"_mhand");//���o�̤j��P�ƶq

        if(hnum==max_hand) return notify_fail("�A����P�ƶq�w�g���F!!\n");;

        if((max_hand-hnum)>cnum){//�P�ռƶq�p���P��
           if(query("1p")==me)
             message_vision(HIG"\n"+query("1p")->short()+"���S�P�F�A�ܥi���L��F�A�ӧQ�̬O"+query("2p")->short()+"�I�I���߮��ߡI�I\n"NOR, me);
           else
             message_vision(HIG"\n"+query("2p")->short()+"���S�P�F�A�ܥi���L��F�A�ӧQ�̬O"+query("1p")->short()+"�I�I���߮��ߡI�I\n"NOR, me);
           call_out("lost",0,me);
           return 1;
        }

        message_vision(HIG"\n$N"HIG"��F�P�ɨ�ۤv����P��\n"NOR,me);
        if(sizeof(hcards)<1) hcards=([]);
        for(i=0;i<(max_hand-hnum); i++){//��P
          card=keys(data);
          n=random(sizeof(data)-1);
          hcards[card[n]]=p;
          write("�A���@�i"+card[n]->name()+"\n");
          map_delete(data,card[n]);
        }
        set("cards/"+p,data);
        set("hcards/"+p,hcards);

        write("OK.�A���P�թ|��"+chinese_number(sizeof(data))+"�i�d���C\n");
        do_over(me);
        if(sizeof(data)<5) write(HIR"ĵ�i�I�I�A�P�դ����ƵP�i�Ƥw�g�֭n�⧹�A�Ъ`�N�C\n"NOR);
        return 1;
}

int do_dump(string arg)
{
   object me,a,b,*cdata,ob,m,player;
   string *saying_name = ({ "�ݧڪ��A","�X�ӧa�I","�l��С�","�ڨϥ�","�ݲM���I�o�N�O�ڪ�.." });
   string saying = saying_name[random(sizeof(saying_name))];
   int i,num,size,max_pk;
   mapping hcards;
   string *card,p,def;
   object *magic;

        me = this_player();

        ob=this_object();
        a=query("1p");
        b=query("2p");

        if(me!=a && me!=b) return 0;

        player=query("player");
        if(player!=me) return notify_fail("�{�b���O����A���ܡC\n");

        if(query("dump")) return notify_fail("�A�o�^�X�w�g�l��L�԰����~�F�I\n");;

        p=query(me->query("id"));

        if(!arg) return notify_fail("���O�榡 dump + ��P�s�� (�i�� view hand ���)\n");

//      cdata = all_inventory();//���o�Գ��W���d�����
        cdata = query_cards("pk");//���o�Գ��W���d�����
        max_pk=query(p+"_mpk");//���o�̤j���W���~�ƶq
        if(get_amount(p,cdata)>max_pk) return notify_fail("�A���i���W���԰��d�w�g�뺡�F!!\n");

        if(!sscanf(arg,"%d %s",num,def)) sscanf(arg,"%d",num);//���o�d���s��
        hcards=query("hcards/"+p);//���o��P���
        size=sizeof(hcards);
        if(sizeof(hcards)<1) return notify_fail("�A���⤤�w�g�S���P�i�H�ϥΤF!!\n");
        card=keys(hcards);
        if(num>(size-1) || num<0) return notify_fail("���O�榡 dump + ��P�s�� (�i�� view hand ���)\n");
        if(card[num]->query("kind")=="magic")
           return notify_fail("dump�O�ΨӥX���~�d�M�����d���A�]�k�d�ХαM�Ϋ��O�I\n");

        m=new(card[num]);
        m->move(ob);
        map_delete(hcards,card[num]);
        set("hcards/"+p,hcards);

        m->set("owner",p);//�d�����]�w
        if(def || m->query("kind")=="trap"){//���u�򳴨��d���B�z�覡�ۦP.
          m->set("defend",1);//���u
          m->set("hide",1);//�\�P
          message_vision(HIG"\n$N"HIG"���D�G"NOR"�ڦb�i���W�\�W\�@�i�d�I\n",me);
        }else message_vision(HIG"\n$N"HIG"���D�G"NOR""+saying+"�u"+m->name()+"�v�A�Ĩ�"HIR"�u�������A�v"NOR"�I\n", me);

        if(query("earth") == m->query("earth")) {
           if(def)
             write(HIM"�A���ۻy�����D�G"NOR"�]�����ҾA���O�����Y�A�ڪ�"+
               m->name()+"�ٯണ�� "HIW"200"NOR" ���������O�I\n");
           write("�A�Q�쪺�Ѧh���c���ơA�������Ӱ����ۡA���S���¨������o�{�C\n");
           m->add("ap",200);    
           if(!def)
              message_vision(HIG"$N"HIG"���D�G"NOR"�]�����ҾA���O�����Y�A�ڪ��u"+
              m->query("name")+"�v�ٯണ�� "HIW"200"NOR" ���������O�I�I�I\n", me);
           m->add("ap",200);
        }
        set("dump",1);//�l��L�Ǫ��άO��W�����d��
// ***************************** �d���S��\��(start) *****************************
//      if(m->query("do_open")) m->do_open(this_object(),me);
        if(!m->query("hide")) if(m->do_open(this_object(),me,0,"dump")) return 1;
        if(magic=query("magic")){//�@�q�]�k
            for(i=0;i<sizeof(magic);i++){
              if(!objectp(magic[i])) continue;
//            magic[i]->check_magic(this_object(),me,"dump",0);//�A���Ұ��]�k
              if(magic[i]->check_magic(this_object(),me,m,0,"dump"))return 1;//�A���Ұ��]�k
            }
        }
// ***************************** �d���S��\��(end) *****************************
        return 1;
}

int die(object card)
{
// card : �ǤJ���󫬺A���d��
// card2: �ǤJ��r�ɫ��A���d��
// die_cards�Ҧs���O���󫬺A�����

   mapping d_cards;
   string owner;
   object new_card;

        owner=card->query("owner");//���o�֦���(1p��2p)
        new_card=new(base_name(card));
        destruct(card);
        new_card->set("die",1);
        new_card->move(this_object());
        return 1;
}

int do_pk(string arg)
{
   object me,a,b,target;
   int my=0,your=0,amount;
   string p;
   object *cdata;
   int my_ap,your_ap,my_dp,your_dp;
   object damage_p;
   string s_condition;
   object *magic;
   int i;

        me = this_player();
        a=query("1p");
        b=query("2p");

        if(me!=a && me!=b) return 0;
        if(query("player")!=me) return notify_fail("�{�b���O����A���ܡC\n");

        p=query(me->query("id"));
        if(!arg) return notify_fail("���O�榡: pk <�ڤ�ǼƦr> <�Ĥ�ǼƦr>\n");
        sscanf(arg,"%d %d",my,your);

//      cdata = all_inventory();//���o�Գ��W���d�����
        cdata=query_cards("pk");
        if(my<0 || my>(sizeof(cdata)-1)) return notify_fail("���O�榡: pk <�ڤ�ǼƦr> <�Ĥ�ǼƦr>\n");

        if(cdata[my]->query("owner")!=p)
//        return notify_fail(cdata[my]->name()+"�S���O�A�a�����~�A�A�sԣ�H\n");
          return notify_fail("���S���O�A�a�����~�A�A�sԣ�H\n");
        if(!cdata[my]->query("attrib"))
          return notify_fail("���O�榡: pk <�ڤ�ǼƦr> <�Ĥ�ǼƦr>\n");

        if(your<0 ||your>(sizeof(cdata)-1)){
          if(p=="1p") target=b;
          else target=a;        
        }else target=cdata[your];
        if(target->query("owner")==p) return notify_fail("�A�Q���˦ۤv���Ǫ��ܡH\n");

//      write(cdata[my]->name());
//      write(cdata[your]->name());
//      write(target->name());

//�S���p
        if(cdata[my]->query("freeze") > query("round"))
          return notify_fail(cdata[my]->name()+"�b�o�^�X�L�k��ʡA�����A��"+chinese_number(
            cdata[my]->query("freeze")-query("round"))+"�^�X\n");
        else cdata[my]->delete("freeze");

        if(cdata[my]->query("act")) 
          return notify_fail(cdata[my]->name()+"�b�o�^�X�w�g��ʹL�F\n");
        if(cdata[my]->query("defend")) return notify_fail("�u�Ʃ��~����i��԰�\n");
        if(query("round") == 1) return notify_fail("�Ĥ@�^�X����i��԰�\n");
//
        amount=get_amount(p=="1p"?"2p":"1p",cdata);//���o�Ĥ���W���~�ƶq
//      write(""+amount);
        if(userp(target)){//�����������a
          if(amount>0)return notify_fail("����i���W�٦��԰����~�������A�L�k�����缾�a�i������C\n");
          else{
            message_vision(HIG"\n$N"HIG"���D�G"NOR"�A���i���W�w�g�S����O�@�A���԰����~�F�I�I�ҥH.....\n"NOR,me);
            message_vision(HIG"\n$N"HIG"���D�G"NOR"�N���A�N�Ө��کҦ��������a�I�I\n"NOR,me);
            if(cdata[my]->query("a_msg"))
                message_vision(HIG"\n$N"HIG"���D�G"NOR"�԰��I"+cdata[my]->name()+
                    "������$n�����I�I"+cdata[my]->query("a_msg")+"\n"NOR,me,target);
            else
                message_vision(HIG"\n$N"HIG"���D�G"NOR"�԰��I"+cdata[my]->name()+
                    "������$n�����I�I\n"NOR,me,target);
            add(query(target->query("id"))+"_hp",-cdata[my]->query("ap"));
            cdata[my]->set("act",1);
          }
          damage_p=target;
        }else{//�����԰����~
          my_ap=cdata[my]->query("ap");
          my_dp=cdata[my]->query("dp");
          your_ap=target->query("ap");
          your_dp=target->query("dp");
          cdata[my]->set("act",1);
          if(target->query("hide")) {
            message_vision(HIC"\n�Q�л\\���d½�}�F�A�L���u���ح�ӬO"+NOR+target->name()+HIC
                "�I�I\n",me);
            target->delete("hide");
          }
          if(cdata[my]->query("a_msg"))
            message_vision(HIG"\n$N"HIG"���D�G"NOR"�W�a�I"+cdata[my]->name()+
                "�I�I������誺"+target->name()+"�I"+cdata[my]->query("a_msg")+"\n",me);
          else
            message_vision(HIG"\n$N"HIG"���D�G"NOR"�W�a�I"+cdata[my]->name()+
                "�I�I������誺"+target->name()+"�I\n",me);

// ***************************** �d���S��\��(start) *****************************
          if(target->do_trap(this_object(),me,cdata[my])) return 1;//����
          if(magic=query("magic")){//�@�q�]�k
            for(i=0;i<sizeof(magic);i++){
              if(!objectp(magic[i])) continue;
              if(magic[i]->check_magic(this_object(),me,cdata[my],target,"pk"))
                return 1;//�A���Ұ��]�k
            }
          }
// ***************************** �d���S��\��(end) *****************************

          if(!target->query("defend")){//�Ĥ�Ǫ��O�������A(start)
            if((my_ap-your_ap)>0){
              message_vision(HIG"\n$N"HIG"���D�G"NOR"�������I���P���}�F�A��"+target->name()+
                  "�I�I\n",me);
              add(target->query("owner")+"_hp",-(my_ap-your_ap));
              damage_p=query(target->query("owner"));//��������
              die(target);
            }else if((my_ap-your_ap)==0){
              message_vision(HIR"\n"+cdata[my]->name()+"�M"+target->name()+"�ѩ�԰��O�۷�
                  �A�ӦP�k��ɤF�I\n",me);
              die(target);
              die(cdata[my]);
            }else{
              message_vision("\n$N�G�s�@�n�A���y�u���]�w���H�H�H�v�����C\n",me);
              message_vision(HIG"\n$N"HIG"���D�G"NOR"�ڡI�I�I�ڪ�"+cdata[my]->name()
                  +"�Q�A�����F�I�I\n",me);
              add(p+"_hp",my_ap-your_ap);
              damage_p=me;//��������
              die(cdata[my]);
            }
          }//�Ĥ�Ǫ��O�������A(end)
          else{//�Ĥ�Ǫ��O�u�ƪ��A(start)
            if((my_ap-your_dp)>0){
              message_vision(HIG"\n$N"HIG"���D�G"NOR"�������I���M���˧A�ͩR�ȡA���٬O���P���}�F�A��"+target->name()+"�I�I\n",me);
              die(target);
            }else if((my_ap-your_dp)==0){
              message_vision(HIR"\n"+cdata[my]->name()+"�M"+target->name()+"�ѩ��u�۷�A���y������v�T�I\n",me);
            }else{
              message_vision("$N�G�s�@�n�A���y�u���]�w���H�H�H�v�����C\n",me);
              message_vision(HIG"\n$N"HIG"���D�G"NOR"�A��"+target->name()+"�֤ӫp�F��...�ڼ��F"+(your_dp-my_ap)+"�����ͩR\n",me);
              add(p+"_hp",my_ap-your_dp);
              damage_p=me;//��������
            }
          }//�Ĥ�Ǫ��O�u�ƪ��A(end)
        }

        if(damage_p){
          if(query(query(damage_p->query("id"))+"_hp") > 0)
            message_vision(HIW"\n$N"HIW"�ثe�ͩR���ٳѤU "+query(query(damage_p->query("id"))+"_hp")
                    +" ���C\n"NOR,damage_p);
          else {
            message_vision(HIW"\n$N"HIW"�ͩR�ȳQ���s�F�A��Ӫ��O$n�I�I���߮��ߡI�I�C
                    \n"NOR,damage_p,damage_p==a?b:a);
            call_out("lost",0,damage_p);
        }}
        return 1;
}

int do_magic(string arg)
{
   object me,a,b,ob;
   int num,target=0,size;
   string p;
   mapping hcards=([]);
   string *card;
   object *cdata=({});

        me = this_player();
        p=query(me->query("id"));
        a=query("1p");
        b=query("2p");

        if(me!=a && me!=b) return 0;
        if(query("player")!=me) return notify_fail("�{�b���O����A���ܡC\n");

        if(!arg) return notify_fail("���O�榡: magic <��P�s��> <���W���~�s��>\n");

        sscanf(arg,"%d %d",num,target);
        hcards=query("hcards/"+p);//���o��P���
        if(sizeof(hcards)<1) return notify_fail("�A���⤤�S������d���i�H�ϥ�!!\n");
        card=keys(hcards);
        size=sizeof(hcards);
        if(num<0 || num>(size-1)) return notify_fail("���O�榡: magic <��P�s��> <���W���~�s��>\n");
        if(card[num]->query("kind")!="magic") return notify_fail("�u"+card[num]->name()+"�v�o�i�d�ä��O�]�k�d\n");

//      cdata=all_inventory();
        cdata=query_cards("pk");
        size=sizeof(cdata);
        if(target<0 || target>(size-1)) 
           return notify_fail("�ثe�i���W�䤣��A�һ��n���I�k��H���԰����~�C\n");
        ob=new(card[num]);
        ob->set("owner",p);
        if(ob->query("forever")) message_vision(HIG"$N"HIG"���D�G"NOR"�ݧڪ��ä[�]�k�d�ССu$n�v\n",me,ob);
        else message_vision(HIG"$N"HIG"���D�G"NOR"�ݧڪ��]�k�d�ССu$n�v\n",me,ob);
        map_delete(hcards,card[num]);
        set("hcards/"+p,hcards);
// ***************************** �d���S��\��(start) *****************************
        if(ob->do_open(this_object(),me,cdata[target],"magic")) return 1;
// ***************************** �d���S��\��(end) *****************************
        die(ob);//�e�i�X��

        return 1;
}

int do_tactic(string arg)
{
   object me,a,b;
   string p;
   object *cdata;
   int num,size;
   object *magic;
   int i;

        me = this_player();
        p=query(me->query("id"));
        a=query("1p");
        b=query("2p");

        if(me!=a && me!=b) return 0;
        if(query("player")!=me) return notify_fail("�{�b���O����A���ܡC\n");

        if(!arg) return notify_fail("���O�榡: tactic <���W���~�Ʀr>\n");
        sscanf(arg,"%d",num);

//      cdata=all_inventory();
        cdata=query_cards("pk");
        if(num<0 || num>(sizeof(cdata)-1)) 
           return notify_fail("���O�榡: tactic <���W���~�Ʀr>\n");

        if(cdata[num]->query("owner")!=p)
           return notify_fail("���S���O�A�a�����~�A�A�L�k�o�򰵡C\n");
        if(cdata[num]->query("kind")=="magic" ||cdata[num]->query("kind")=="trap")
           return notify_fail("�A�u����԰����~�U�����O�C\n");
        if(cdata[num]->query("act")) return notify_fail("���b�o�^�X�w�g��ʹL�F�C\n");
        if(cdata[num]->query("freeze") > query("round")) 
           return notify_fail("�L�b�o�^�X�L�k��ʡA�����A��"+(chinese_number(cdata[num]->query("freeze")-query("round")))+"�^�X\n");

        if(!cdata[num]->query("defend")){
           message_vision(HIG"\n$N"HIG"���D�G"NOR"�ڱN"+cdata[num]->name()+"���ܬ�"HIY"�u�u�ƪ��A�v"NOR"�I\n",me);
           cdata[num]->set("defend",1);
        }else{
           message_vision(HIG"\n$N"HIG"���D�G"NOR"�ڱN"+cdata[num]->name()+"���ܬ�"HIY"�u�������A�v"NOR"�I\n",me);
           cdata[num]->delete("defend");
           cdata[num]->delete("hide");
// ***************************** �d���S��\��(start) *****************************
//         if(cdata[num]->query("do_open")) cdata[num]->do_open(this_object(),me);
           if(cdata[num]->do_open(this_object(),me,0,"tactic"))return 1;
           if(magic=query("magic")){//�@�q�]�k
             for(i=0;i<sizeof(magic);i++){
//             magic[i]->check_magic(this_object(),me,"tactic",0);//�A���Ұ��]�k
               if(!objectp(magic[i])) continue;
               if(magic[i]->check_magic(this_object(),me,cdata[num],0,"tactic"))return 1;//�A���Ұ��]�k
             }
           }
// ***************************** �d���S��\��(end) *****************************
        }

        return 1;
}

int do_history(string arg)
{
   object env,me,a,b,m,p;
   int i,pn;

        me = this_player();
        env = environment(me);

        write("���Z��\n================================================================================\n");
        for(i=0; i<query("score_num"); i++) {
           write(""HIY"��"+chinese_number(i+1)+"��"NOR"  "HIW"�ӧQ�̡G"+
             query("fight_"+(i+1)+"/winner")+NOR+"  "HIR"���Ѫ̡G"+query("fight_"+(i+1)+
             "/loster")+NOR+"  "HIM"�ӧQ�^�X�G"+chinese_number(query("fight_"+(i+1)+
             "/round"))+NOR+"  "HIB"�ҳѥͩR�G"+query("fight_"+(i+1)+"/hp")+NOR+"\n");
        }
        if(i==0) write("�ۭ��s�Ұʨ�{�b�A�|�L��Ƶn�J\n");
        write("================================================================================\n");
        return 1;
}

int do_cover(string arg)
{
   object me,a,b;
   string p;

        me = this_player();
        p=query(me->query("id"));
        a=query("1p");
        b=query("2p");

        if(me!=a && me!=b) return 0;
        if(!query("player")){
           delete("1p");
           delete(me->query("id"));
           message_vision(HIG"\n"+me->name()+"�h�X�F�P��!!\n",me);
           return 1;
        }

        if(p="1p")
             message_vision(HIG"\n"+me->name()+"�еP�F�A�L�ӻ{�ۤv�鵹�F"+query("2p")->name()+"�A����"+query("2p")->name()+"�ӧQ�I\n"NOR,me);
        else message_vision(HIG"\n"+me->name()+"�еP�F�A�L�ӻ{�ۤv�鵹�F"+query("1p")->name()+"�A����"+query("1p")->name()+"�ӧQ�I\n"NOR,me);
        call_out("lost",0,me);

        return 1;
}

int do_go(string arg)
{
   object me;

        me = this_player();
        if((query("1p")==me)||(query("2p")==me)){
          write(HIR"�L���@�U�A�M���ɽФť��N���ʡC\n"NOR);
          return 1;
        }
}

int lost(object me)
{
   object a,b,winner,loster;
   string p;
   int i;
   object *inv;

        if(!me) me = this_player();
        a=query("1p");
        b=query("2p");

        if(me!=a && me!=b) return 0;
        if(me==a){ loster=a; winner=b;}
        else {loster=b; winner=a;}

        add("score_num",1);
        set("fight_"+query("score_num")+"/winner",winner->name());
        set("fight_"+query("score_num")+"/loster",loster->name());
        set("fight_"+query("score_num")+"/round",query("round"));
        set("fight_"+query("score_num")+"/hp",query(query(winner->query("id"))+"_hp"));

        delete(a->query("id"));  delete(b->query("id"));
        delete("1p"); delete("2p");
        delete("1p_hp"); delete("2p_hp");
        delete("1p_mhand"); delete("2p_mhand");
        delete("1p_mpk"); delete("2p_mpk");
        delete("player"); delete("earth");
        delete("round"); delete("check_round"); 
        delete("hcards");  delete("cards"); 

        inv = all_inventory();
        for(i=0;i<sizeof(inv);i++) {
           destruct(inv[i]);
        }

        message_vision(HIR"\n���W�Ҧ��԰����~���@�|���������F�C\n"NOR, this_player());
        return 1;
}

