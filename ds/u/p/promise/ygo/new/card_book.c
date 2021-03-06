// this is a ob wrote by saveob
#include <ansi.h>
inherit ITEM;
inherit F_SAVE;

void create()
{
        set_name("卡片收集簿",({ "card book","book","card"}));
        set_weight(100);
        if(clonep())
           set_default_object(__FILE__);
        else{
           set("maker","ghoster");
//         set("equipped","mark");
           set("long",@long
一本可以放入卡片的收集本.
指令:  
        list_card -- 列出收集本裡所存放的卡片.
        give_card -- 將卡片放入收集本中.
        get_card  -- 將卡片從收集本中取出.
        set_card  -- 設定或取消卡片為戰鬥牌組.
        view_card -- 觀看單一卡片的能力.
long);
           set("unit","本");
           set("value",500);
           set("no_change",1);
        }
}

int query_autoload()
{
//      save();
        return 1;
}

mapping cards=([]);//所有的卡片資料
mapping fcards=([]);//戰鬥牌組的卡片資料
mapping ccards=([]);//一般卡片的資料

int fight_cards;
int common_cards;

mapping query_cards(){return cards;}//傳回所有的卡片資料
mapping query_fcards(){return fcards;}//傳回戰鬥牌組卡片資料
mapping query_ccards(){return ccards;}//傳回一般卡片資料

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
          cards=([]);//所有的卡片資料
          fcards=([]);//戰鬥牌組的卡片資料
          ccards=([]);//一般卡片的資料
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
        if(sizeof(cards)<1) return notify_fail("這是一本空的"+name()+".\n");
        count_cards();
        card=keys(cards);
        write(HIB"你所擁有的卡片如下:\n\n"NOR);
        write(HIR"  [一般卡片] "NOR+YEL+"共 "+common_cards+" 種\n\n"NOR);
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
                  str+=card[i]->query("attrib")+HIR" 攻擊力；"+card[i]->query("ap")+NOR
                       +"，"+HIB"守備力；"+card[i]->query("dp")+NOR""+
                       (card[i]->query("doc")?("\n\t\t\t"+card[i]->query("doc")):"")+"\n";
                  else str+=card[i]->query("doc")+"\n";
             }
           }
        }

        j=0;
        str+=HIR"\n\n  [戰鬥牌組] "NOR+YEL+"共 "+fight_cards+" 種\n\n"NOR;
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
                  str+=card[i]->query("attrib")+HIR" 攻擊力；"+card[i]->query("ap")+NOR
                       +"，"+HIB"守備力；"+card[i]->query("dp")+NOR""+
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
//      if(!arg || !ob=present(arg,this_player())) return notify_fail("你的身上沒有這樣東西!!\n");
//      if(!arg || !ob=present(arg,environment(this_player()))) return notify_fail("你的身上沒有這樣東西!!\n");
        if(!arg) return notify_fail("指令格式: give_card [卡片id|all]\n");
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
            if(sizeof(cards)>99) return notify_fail(name()+"只能放入100張不同種類的卡片!!\n");
            cards[base_name(all[i])]++;
            write("你將"+all[i]->name()+"放入"+name()+"內.\n");
            destruct(all[i]);
            count_cards();
          }
          do_save();
          return 1;
        }
        if(!ob=present(arg,this_player())) return notify_fail("你身上沒有這樣東西!!\n");
        if(!ob->query("card")) return notify_fail("你只能將卡片放入"+name()+"中!!\n");
        if(sizeof(cards)>99) return notify_fail(name()+"只能放入100張不同種類的卡片!!\n");
        if(cards[base_name(ob)]<100){
          if(cards[base_name(ob)]>2) return notify_fail(name()+"只能存放三張同種類的卡片!!\n");
        }
        else{
          if(cards[base_name(ob)]>102) return notify_fail(name()+"只能存放三張同種類的卡片!!\n");
        }
        write("你將"+ob->name()+"放入"+name()+"內.\n");
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

        if(!arg) return notify_fail("指令格式: get_card <數字>\n");

        reset_book();
        sscanf(arg,"%d",i);
        card=keys(cards);
        if(i<0 || i>(sizeof(card)-1)) return notify_fail("指令格式: get_card <數字>\n");
        if(!card[i]) return notify_fail("指令格式: get_card <數字>\n");
        ob=new(card[i]);
        write("你將"+ob->name()+"從"+name()+"內取出.\n");
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
        if(!arg) return notify_fail("指令格式: set_card <數字>\n");
        
        sscanf(arg,"%d",i);
        card=keys(cards);
        if(i<0 || i>(sizeof(card)-1)) return notify_fail("指令格式: set_card <數字>\n");
        if(!card[i]) return notify_fail("指令格式: set_card <數字>\n");
        count_cards();
        if(cards[card[i]]<100){
          if(fight_cards>39) return notify_fail("你最多只能放40張卡到戰鬥牌組中!!\n");
          write("你將"+card[i]->name()+"放入戰鬥排組當中.\n");
          cards[card[i]]=cards[card[i]]+100;
        }
        else{
          write("你將"+card[i]->name()+"從戰鬥牌組中取出放入一般卡片裡.\n");
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
        if(!arg) return notify_fail("指令格式: view_card <數字>\n");
        
        sscanf(arg,"%d",i);
        card=keys(cards);
        if(i<0 || i>(sizeof(card)-1)) return notify_fail("指令格式: view_card <數字>\n");
        if(!card[i]) return notify_fail("指令格式: view_card <數字>\n");
        str+=card[i]->name()+"\t";
        if(card[i]->query("attrib"))
          str+=card[i]->query("attrib")+HIR" 攻擊力；"+card[i]->query("ap")+NOR
                       +"，"+HIB"守備力；"+card[i]->query("dp")+NOR""+
                       (card[i]->query("doc")?("\n\t\t"+card[i]->query("doc")):"")+"\n";
        else str+=card[i]->query("doc")+"\n";
        write(str);
        return 1;
}

void owner_is_killed() { destruct(this_object()); }
