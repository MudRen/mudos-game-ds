//�ѱ��m�ľ� beta 
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("�ѱ��m�ľ�",({"medication machine","machine"}));
        set_weight(100);
                set("value",0);
                set("no_drop",1);
                set("can_give",1);
                set("unit","��");
                set("long","\n");
         set_max_encumbrance(10000);
         set_max_capacity(50);

        setup();
}

void init()
{
     add_action("do_make", "make");
}

int element_counting(int add, int sub)
{
    int x = add/2 - sub/2;
    return x;
}
    
void dest_all(object *obs){ for(int i=0;i<sizeof(obs);i++) destruct(obs[i]); }

void failure(object *obs, object ob)
{
     dest_all(obs);
     new(__DIR__"ash")->move(ob);
}

void pill_done(string top_element, string sec_element, int total)
{
     float percent_of_top_element = this_object()->query_temp("attribute/"+top_element)/total,
           percent_of_sec_element = this_object()->query_temp("attribute/"+sec_element)/total;
           
           tell_object(this_player(),"no 1 = "+percent_of_top_element+" "+top_element+"\n");
}
     
void element_compare(int gold, int wood, int water, int fire, int earth)
{
     int x, y, temp, *elements = ({gold, wood, water, fire, earth}), total = gold + wood + water + fire + earth;
     string *s_elements = ({"��", "��", "��", "��", "�g"}), element,top_element = "��", sec_element = "��"; 
     
     for(x=0;x<4;x++){
         for(y=x+1;y<5;y++) {
                            tell_object(this_player(),elements[y]+" "+elements[x]+"\n");
             if( elements[y] > elements[x] ){
                 temp = elements[x];
                 elements[x] = elements[y];
                 elements[y] = temp;
             }
         }
     }

     for(y=0;y<2;y++){
         for(x=0;x<5;x++){
             temp = this_object()->query_temp("attribute/"+s_elements[x]);
             if( temp = elements[y] ){
                if( y = 0 ){ top_element = s_elements[x]; }
                else if( y = 1 ){ sec_element = s_elements[x]; }
             }
         }
     }
     tell_object(this_player(),top_element+" "+sec_element+"\n");
//     pill_done( top_element, sec_element, total);
}
     
void element_count()
{
    object me = this_player(), ob = this_object(), *obs;
    mapping attribute;
    string *elements;
    int value, x, gold_temp, wood_temp, water_temp, fire_temp, earth_temp, gold, wood, water, fire, earth, total;
    float p_gold, p_wood, p_water, p_fire, p_earth;
    
    obs = all_inventory(ob);
    
    for(x=0;x<sizeof(obs);x++){
        
        if( !obs[x]->query("attribute") ) { failure(obs, ob); break; }
        else {
             attribute = obs[x]->query("attribute");
             elements = keys(attribute);
             value = obs[x]->query("attribute/"+elements[0]);
             ob->add_temp("attribute/"+elements[0], value);
             }
    }
    if( obs ) dest_all(obs);
    gold_temp  = ob->query_temp("attribute/��");
    wood_temp  = ob->query_temp("attribute/��");
    water_temp = ob->query_temp("attribute/��");
    fire_temp  = ob->query_temp("attribute/��");
    earth_temp = ob->query_temp("attribute/�g");
    
    gold  = gold_temp + element_counting(earth_temp, fire_temp);
    wood  = wood_temp + element_counting(water_temp, gold_temp);
    water = water_temp + element_counting(gold_temp, earth_temp);
    fire  = fire_temp + element_counting(wood_temp, water_temp);
    earth = earth_temp + element_counting(fire_temp, earth_temp);
    tell_object(this_player(),gold+" "+wood+" "+water+" "+fire+" "+earth+" ");
    element_compare(gold, wood, water, fire, earth);
}
       
int do_make()
{
//    object me = this_player(), ob = this_object();
    element_count();
    return 1;
}
