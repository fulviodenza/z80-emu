(*This is a pseudocode for Ocaml compiler*)

let match_ld str = 
    match str with 
        "a" -> ( 
            let arg = next_token in 
            match arg with 
            "bc" -> [0x0A] |
            _ -> [0x01; int_of_string arg; int_of_string next_token]
        )
        | "bc" ->( 
            let arg = next_token in   
            match arg with   
                    "a" -> [0x02] |
                    _ ->  [0x01; int_of_string arg]) 
        | "b" -> (
            let arg = next_token in 
            match next_token with  
                _ -> [0x01; int_of_string arg] )
        | "de" ->  (
            let arg = next_token in
            match arg with   
                "a" -> [0x12] |
                _ -> [0x11; int_of_string arg]) |
        _ -> raise "unrec load instruction " ;;

let match_inc str = 
    match str with 
        "bc" -> [0x03] |
        "b" -> [0x04] | 
        "c" -> [0x0C] | 
        "de" -> [0x013] |
        _ -> raise "unrec inc instruction" ;;let match_inc str = 
let match_dec str =     
    match str with 
        "b" -> [0x05] | 
        "c" -> [0x0D] | 
        _ -> raise "unrec dec instruction" ;;
let match_add str = 
    match add with
        "hl" -> ( let arg = next_token in
                    match arg with
                        "bc" -> [0x09] |
                        _ -> raise "unrec add hl, " ) 
        | "a" -> (let arg = next_token in 
                    match arg with
                        "b" -> [0x80] |
                        _ -> raise "unrec add a, ")
        _ -> raise "unrec add"

let match_instr i= 
    match i with
    "nop" -> [0x00] |
    "ld" -> match_ld (next_token) |
    "inc" -> match_inc (next_token) |
    "dec" -> match_dec (next_token) |
    "add" -> match_add (next_token) |
    "rrca" -> [0x0F] ;;
    "djnz" -> [0x10; int_of_string next_token] ;;

let rec compile source = 
    match source with 
        instr :: " " :: rest  -> 
            match_instr instr :: compile rest
        [] -> []