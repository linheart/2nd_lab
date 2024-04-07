import Control.Exception
import Text.Read (readMaybe)

err :: String -> a
err exc = throw (ErrorCall exc)

initValue :: IO Int
initValue = do
    input <- getLine
    case readMaybe input of
        Just val -> if val > 0 then return val else err "Invalid input"
        Nothing -> err "Invalid input"

func :: Int -> Int -> Int -> Int
func s n m
    | s * m > (s - div s 7) * n = -1
    | otherwise = ceiling (fromIntegral (s * m) / fromIntegral n)

main :: IO ()
main = do
    s <- initValue
    n <- initValue
    m <- initValue
    print (func s n m)
