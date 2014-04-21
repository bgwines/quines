
import Data.Char

escape :: String -> String
escape s = concat . map escape_char $ s
	where escape_char ch = 
		if (ord ch == 10) -- newline
			then [chr 92, 'n']
			else if (ord ch == 9) -- tab
				then [chr 92, 't']
				else [ch]

fix :: String -> String
fix s =
	let
		(s', s'') = splitAt 386 s
		quote = [chr 34]
	in
		s' ++ quote ++ (escape s) ++ quote ++ s''

main = do
	let s = "\nimport Data.Char\n\nescape :: String -> String\nescape s = concat . map escape_char $ s\n\twhere escape_char ch = \n\t\tif (ord ch == 10) -- newline\n\t\t\tthen [chr 92, 'n']\n\t\t\telse if (ord ch == 9) -- tab\n\t\t\t\tthen [chr 92, 't']\n\t\t\t\telse [ch]\n\nfix :: String -> String\nfix s =\n\tlet\n\t\t(s', s'') = splitAt 386 s\n\t\tquote = [chr 34]\n\tin\n\t\ts' ++ quote ++ (escape s) ++ quote ++ s''\n\nmain = do\n\tlet s = \n\tputStrLn $ fix s"
	putStrLn $ fix s
