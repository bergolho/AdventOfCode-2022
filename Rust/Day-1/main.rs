use std::io;

fn main () -> std::io::Result<()> {
    let mut input = String::new();
    let stdin = io::stdin();
    
    while stdin.read_line(&mut input).expect("Cannot read file!") != 0 {
        println!("{}", input);
    }
        
    Ok(())
    /*
    let file = File::open("in2").expect("File not found!");
    let buf_reader = BufReader::new(file);

    for line in buf_reader.lines() {
        println!("{}", line?);
    }
    Ok(())
    */
}