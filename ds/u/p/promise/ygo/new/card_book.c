// this is a ob wrote by saveob
#include <ansi.h>
inherit ITEM;
inherit F_SAVE;

void create()
{
        set_name("�d������ï",({ "card book","book","card"}));
        set_weight(100);
        if(clonep())
           set_default_object(__FILE__);
        else{
           set("maker","ghoster");
//         set("equipped","mark");
           set("long",@long
�@���i�H��J�d����������.
���O:  
        list_card -- �C�X�������̩Ҧs�񪺥d��.
        give_card -- �N�d����J��������.
        get_card  -- �N�d���q�����������X.
        set_card  -- �]�w�Ψ����d�����԰��P��.
        view_card -- �[�ݳ�@�d������O.
long);
           set("unit","��");
           set("value",500);
           set("no_change",1);
        }
}

int query_autoload()
{
//      save();
        return 1;
}

mapping cards=([]);//�Ҧ����d�����
mapping fcards=([]);//�԰��P�ժ��d�����
mapping ccards=([]);//�@��d�������

int fight_cards;
int common_cards;

mapping query_cards(){return cards;}//�Ǧ^�Ҧ����d�����
mapping query_fcards(){return fcards;}//�Ǧ^�԰��P�եd�����
mapping query_ccards(){return ccards;}//�Ǧ^�@��d�����

int count_cards()
{
   string *card;
   int i;

        fcards=([]);
        ccards=([]);

        fight_cards=0;
        common_cards=0;
        card=keys(cards);
        for(i=0;i<sizeof(card);i++){
          if(cards[card[i]]<100){
            common_cards++;
            ccards[card[i]]=1;
          }else{
            fight_cards++;
            fcards[card[i]]=1;
          }
        }
        return 1;
}

void init()
{
        add_action("do_list","list_card");
        add_action("do_flist","flist");
        add_action("do_save","save_card");
        add_action("do_give","give_card");
        add_action("do_get","get_card");
        add_action("do_set","set_card");
        add_action("do_view","view_card");
        set("owner_id",environment()->query("id"));
        environment()->set_temp("cardbook",this_object());
        if(userp(environment())) set("equipped","mark");
        if(!userp(environment())||!restore()){
          cards=([]);//�Ҧ����d�����
          fcards=([]);//�԰��P�ժ��d�����
          ccards=([]);//�@��d�������
          fight_cards=0;
          common_cards=0;
          return;
        }
//      restore();
        count_cards();
}


int reset_book()
{
        if(query("owner_id")!=environment()->query("id")) init();
        if(environment()->query_temp("cardbook")!=this_object()) init();
        count_cards();
        return 1;
}


string query_save_file()
{
        string id;

        if( !stringp(id = query("owner_id")) ) return 0;
        return DATA_DIR + "user/" + id[0..0] + "/"+id+"/"+"cardbook";
}

int do_save()
{
        save();
        return 1;
}


int do_flist()
{
   int i;
   string *fcard;

        fcard=keys(fcards);
        for(i=0;i<sizeof(fcard);i++){
          write(fcard[i]->name()+"\n");
        }
        return 1;
}


int do_list(string arg)
{
   string *card,str="";
   int i,j=0;

        reset_book();
        if(sizeof(cards)<1) return notify_fail("�o�O�@���Ū�"+name()+".\n");
        count_cards();
        card=keys(cards);
        write(HIB"�A�Ҿ֦����d���p�U:\n\n"NOR);
        write(HIR"  [�@��d��] "NOR+YEL+"�@ "+common_cards+" ��\n\n"NOR);
        for(i=0;i<sizeof(card);i++){
           if(cards[card[i]]<100){
             if(!arg){
               j++;
               if(j>2){
                 j=0;
                 str+="\t("+i+")"+card[i]->name()+YEL".."+cards[card[i]]+NOR"\n";
               }else str+="\t("+i+")"+card[i]->name()+YEL".."+cards[card[i]]+NOR"";
             }else{
                  str+="\t"+"("+i+")"+card[i]->name()+"\t";
                  if(card[i]->query("attrib"))
                  str+=card[i]->query("attrib")+HIR" �����O�F"+card[i]->query("ap")+NOR
                       +"�A"+HIB"�u�ƤO�F"+card[i]->query("dp")+NOR""+
                       (card[i]->query("doc")?("\n\t\t\t"+card[i]->query("doc")):"")+"\n";
                  else str+=card[i]->query("doc")+"\n";
             }
           }
        }

        j=0;
        str+=HIR"\n\n  [�԰��P��] "NOR+YEL+"�@ "+fight_cards+" ��\n\n"NOR;
        for(i=0;i<sizeof(card);i++){
           if(cards[card[i]]>100){
             if(!arg){
               j++;
               if(j>2){
                 j=0;
                 str+="\t("+i+")"+card[i]->name()+YEL".."+(cards[card[i]]-100)+NOR"\n";
               }else str+="\t("+i+")"+card[i]->name()+YEL".."+(cards[card[i]]-100)+NOR"";
             }else{
                  str+="\t"+"("+i+")"+card[i]->name()+"\t";
                  if(card[i]->query("attrib"))
                  str+=card[i]->query("attrib")+HIR" �����O�F"+card[i]->query("ap")+NOR
                       +"�A"+HIB"�u�ƤO�F"+card[i]->query("dp")+NOR""+
                       (card[i]->query("doc")?("\n\t\t\t"+card[i]->query("doc")):"")+"\n";
                  else str+=card[i]->query("doc")+"\n";
             }
           }
        }
        this_player()->start_more(str);
        return 1;
}

int do_give(string arg)
{
   object ob;
   int i;
   object *all;

        reset_book();
//      if(!arg || !ob=present(arg,this_player())) return notify_fail("�A�����W�S���o�˪F��!!\n");
//      if(!arg || !ob=present(arg,environment(this_player()))) return notify_fail("�A�����W�S���o�˪F��!!\n");
        if(!arg) return notify_fail("���O�榡: give_card [�d��id|all]\n");
        if(arg=="all"){
          all=all_inventory(this_player());
          for(i=0;i<sizeof(all);i++){
            if(all[i]==this_player())continue;
            if(!all[i]->query("card"))continue;
            if(cards[base_name(all[i])]<100){
               if(cards[base_name(all[i])]>2)continue;
            }else{
               if(cards[base_name(all[i])]>102)continue;
            }
            if(sizeof(cards)>99) return notify_fail(name()+"�u���J100�i���P�������d��!!\n");
            cards[base_name(all[i])]++;
            write("�A�N"+all[i]->name()+"��J"+name()+"��.\n");
            destruct(all[i]);
            count_cards();
          }
          do_save();
          return 1;
        }
        if(!ob=present(arg,this_player())) return notify_fail("�A���W�S���o�˪F��!!\n");
        if(!ob->query("card")) return notify_fail("�A�u��N�d����J"+name()+"��!!\n");
        if(sizeof(cards)>99) return notify_fail(name()+"�u���J100�i���P�������d��!!\n");
        if(cards[base_name(ob)]<100){
          if(cards[base_name(ob)]>2) return notify_fail(name()+"�u��s��T�i�P�������d��!!\n");
        }
        else{
          if(cards[base_name(ob)]>102) return notify_fail(name()+"�u��s��T�i�P�������d��!!\n");
        }
        write("�A�N"+ob->name()+"��J"+name()+"��.\n");
        cards[base_name(ob)]++;
        destruct(ob);
        count_cards();
        do_save();
        return 1;
}



int do_get(string arg)
{
   object ob;
   string *card;
   int i;

        if(!arg) return notify_fail("���O�榡: get_card <�Ʀr>\n");

        reset_book();
        sscanf(arg,"%d",i);
        card=keys(cards);
        if(i<0 || i>(sizeof(card)-1)) return notify_fail("���O�榡: get_card <�Ʀr>\n");
        if(!card[i]) return notify_fail("���O�榡: get_card <�Ʀr>\n");
        ob=new(card[i]);
        write("�A�N"+ob->name()+"�q"+name()+"�����X.\n");
//      write(cards[card[i]]);
        cards[card[i]]=cards[card[i]]-1;
        if(cards[card[i]]<100){
          if(cards[card[i]]<1) map_delete(cards,card[i]);
        }else{
          if(cards[card[i]]<101) map_delete(cards,card[i]);
        }
        ob->move(this_player());
        count_cards();
        do_save();
        return 1;
}

int do_set(string arg)
{
   object ob;
   string *card;
   int i;

        reset_book();
        if(!arg) return notify_fail("���O�榡: set_card <�Ʀr>\n");
        
        sscanf(arg,"%d",i);
        card=keys(cards);
        if(i<0 || i>(sizeof(card)-1)) return notify_fail("���O�榡: set_card <�Ʀr>\n");
        if(!card[i]) return notify_fail("���O�榡: set_card <�Ʀr>\n");
        count_cards();
        if(cards[card[i]]<100){
          if(fight_cards>39) return notify_fail("�A�̦h�u���40�i�d��԰��P�դ�!!\n");
          write("�A�N"+card[i]->name()+"��J�԰��Ʋշ�.\n");
          cards[card[i]]=cards[card[i]]+100;
        }
        else{
          write("�A�N"+card[i]->name()+"�q�԰��P�դ����X��J�@��d����.\n");
          cards[card[i]]=cards[card[i]]-100;
        }
        do_save();
        return 1;
}

int do_view(string arg)
{
   object ob;
   string *card,str="";
   int i;

        reset_book();
        if(!arg) return notify_fail("���O�榡: view_card <�Ʀr>\n");
        
        sscanf(arg,"%d",i);
        card=keys(cards);
        if(i<0 || i>(sizeof(card)-1)) return notify_fail("���O�榡: view_card <�Ʀr>\n");
        if(!card[i]) return notify_fail("���O�榡: view_card <�Ʀr>\n");
        str+=card[i]->name()+"\t";
        if(card[i]->query("attrib"))
          str+=card[i]->query("attrib")+HIR" �����O�F"+card[i]->query("ap")+NOR
                       +"�A"+HIB"�u�ƤO�F"+card[i]->query("dp")+NOR""+
                       (card[i]->query("doc")?("\n\t\t"+card[i]->query("doc")):"")+"\n";
        else str+=card[i]->query("doc")+"\n";
        write(str);
        return 1;
}

void owner_is_killed() { destruct(this_object()); }
