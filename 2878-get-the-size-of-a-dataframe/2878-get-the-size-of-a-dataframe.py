import pandas as pd

def getDataframeSize(players: pd.DataFrame) -> List:
    return [players.shape[0], players.shape[1]]